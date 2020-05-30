%option noyywrap
%x comment
%x STR
%{
    #include "1605070_SymbolTable.h"
    #include <cstdio>
    #include <cstdlib>
    #include <string>
    #include "y.tab.h"

    using namespace std;

    int line_count = 1;
    int total_error = 0;
    extern "C" int yylex();
    extern FILE* logout;

    string current_comment = "";
    string current_str = "";
    int comment_start_line;

    void yyerror(char *);
    SymbolInfo* symbol;
    extern SymbolTable* table;


    void strupr(char *str);
    void filter_string(string& str);
    void error_print(const char *message, const char *symbol);
    void count_line_str(string str);

%}

DIGIT [0-9]+

%%

 /* identifying keywords */

"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"int" {return INT;}
"char" {return CHAR;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"void" {return VOID;}
"return" {return RETURN;}
"println" {return PRINTLN;}
 /* identifying constants */

{DIGIT} {
    string text(yytext);
    symbol = new SymbolInfo(text, "CONST_INT");
    yylval.info = symbol;
    return CONST_INT;

}
{DIGIT}[a-zA-Z_]+ {
    string message = "Invalid prefix on ID or invalid suffix on Number";
    error_print(message.c_str(), yytext);
    total_error++;
}

[0-9]*\.{DIGIT}([eE][-+]?{DIGIT})? |
{DIGIT}[eE][-+]?{DIGIT} {
    symbol = new SymbolInfo(string(yytext), "CONST_FLOAT");
    yylval.info = symbol;
    return CONST_FLOAT;
}

[0-9]*\.([0-9]*\.)+[0-9]* {
    string message = "Too many decimal point";
    error_print(message.c_str(), yytext);
    total_error++;
}

[0-9]*\.?{DIGIT}[eE][-+]?([0-9]*\.)+[0-9]* {
    string message = "Ill formed number";
    error_print(message.c_str(), yytext);
    total_error++;
}

 /* identifying characters */

\'(\\n|\\t|\\\\|\\\"|\\a|\\f|\\r|\\b|\\v|\\0)\' {
    string str(yytext);
    filter_string(str);
    symbol = new SymbolInfo(string(yytext), "CONST_CHAR");
    // yylval = symbol;
    // return CONST_CHAR;

}

\'\\[^nt\\\"afrbv0\'\n] {
    string message = "Unrecogized character constant error";
    error_print(message.c_str(), yytext);
    total_error++;
}

\'[^\\\n][^\n]+\' {
    string message = "Multi character constant error";
    error_print(message.c_str(), yytext);
    total_error++;
}


\'[^\n\\]\' {
    string str = "";
    str += yytext[1];
}
\'[\\]\'|\'[^\n\\\'][^\'\n] {
    string message = "Unterminated character";
    string text(yytext);
    // text.pop_back();
    error_print(message.c_str(), text.c_str());
    total_error++;
}
\'[^\']?[\n] {
    string message = "Unterminated character";
    string text(yytext);
    text.pop_back();
    error_print(message.c_str(), text.c_str());
    total_error++;
    line_count++;
}

\'\' {
    string message = "Empty character constant error";
    error_print(message.c_str(), yytext);
    total_error++;
}
 /* operators and punctuators */
[-+] {
    symbol = new SymbolInfo(string(yytext), "ADDOP");
    yylval.info = symbol;
    return ADDOP;
}

[*/%] {
    symbol = new SymbolInfo(string(yytext), "MULOP");
    yylval.info = symbol;
    return MULOP;
}

\+\+ {
    return INCOP;

}

-- { return DECOP; }

\<=|\<|\>=|\>|==|!= {
    symbol = new SymbolInfo(string(yytext), "RELOP");
    yylval.info = symbol;
    return RELOP;

}

= {
    return ASSIGNOP;
}

&&|\|\| {
    symbol = new SymbolInfo(string(yytext), "LOGICOP");
    yylval.info = symbol;
    return LOGICOP;

}

&|\||\^|<<|>> {
   // return BITOP;

}

! {
    return NOT;

}

\) {
    return RPAREN;
}

\( {
    return LPAREN;
}

\{ {
    return LCURL;
}

\} {
    return RCURL;
}

\[ {
    return LTHIRD;

}

\] {
    return RTHIRD;
}

, {
    return COMMA;

}

; {
    return SEMICOLON;

}



 /* Identifiers */

[a-zA-Z_][a-zA-Z_0-9]* {
    symbol = new SymbolInfo(string(yytext), "ID");
    yylval.info = symbol;
    return ID;
}

[0-9]+[a-zA-Z_0-9]+ {
    string message = "Invalid prefix on ID or invalid suffix on Number";
    error_print(message.c_str(), yytext);
    total_error++;
}

 /* strings */

(\"[^"\n]*\\(\n[^"\n]*\\)*\n[^"\n]*\")|(\"[^"\n]*\") {
    string str(yytext);
    filter_string(str);
    symbol = new SymbolInfo(string(yytext), "STRING");
}

(\"[^"\n]*\\(\n[^"\n]*\\)*\n[^\"\n]*)|(\"[^"\n]*[^\\]) {
    string message = "Unterminated string";
    string test(yytext);
    count_line_str(test);
    error_print(message.c_str(), yytext);
    total_error++;
}


 /* comment */
\/\* { comment_start_line = line_count; BEGIN comment;}
<comment>\*\/ {
    current_comment = "";
    BEGIN INITIAL;
}
<comment>[\n] {
     current_comment += yytext;
     line_count++;
}
<comment>([^*\n])+|. { current_comment += yytext; }
<comment><<EOF>> {
    string message = "Unterminated comment";
    fprintf(logout, "Error at line %d: %s %s\n\n", comment_start_line, message.c_str(), current_comment.c_str());
    total_error++;
    current_comment = "";
    BEGIN INITIAL;
}

\/\/.*\\\n([^\n]+\\\n)*[^\n]*\n|\/\/.*\n {
    string str(yytext);
    str.erase(0,2);
    str.pop_back();
    line_count++;
}

 /*line count */
[\n] { line_count++; }

  /* white space */
[ \t]+ { }


%%

void error_print(const char *message, const char *symbol) {
    fprintf(logout, "Error at line %d: %s %s\n\n", line_count, message, symbol);
}

void strupr(char *str) {
    for(int i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}

void count_line_str(string str) {
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '\n'){
            line_count++;
        }
    }
}

void filter_string(string& str) {
    str.pop_back();
    str.erase(0,1);
    int i = 0;
    for(; i < str.size()-1; i++) {
        if(str[i] == '\\'){
            if(str[i+1] == 'n') {
                str.replace(i, 2, 1,'\n');
                i++;
            } else if(str[i+1] == 'r'){
                str.replace(i, 2, 1, '\r');
                i++;
            } else if(str[i+1] == 't'){
                str.replace(i, 2, 1, '\t');
                i++;
            } else if(str[i+1] == '\\'){
                str.replace(i, 2, 1, '\\');
                i++;
            } else if(str[i+1] == '"'){
                str.replace(i, 2, 1, '"');
                i++;
            } else if(str[i+1] == 'a'){
                str.replace(i, 2, 1, '\a');
                i++;
            } else if(str[i+1] == 'f'){
                str.replace(i, 2, 1, '\f');
            } else if(str[i+1] == 'v'){
                str.replace(i, 2, 1, '\v');
                i++;
            } else if(str[i+1] == 'b'){
                str.replace(i, 2, 1, '\b');
                i++;
            } else if(str[i+1] == '0'){
                str.replace(i, 2, 1, '\0');
                i++;
            } else if(str[i+1] == '\n'){
                line_count++;
                str.replace(i, 2, "");
            }
        }
    }
}