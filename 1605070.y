%{

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include "1605070_SymbolTable.h"
#include <vector>
#include <unordered_set>

using namespace std;
int yyparse(void);
extern "C" int yylex();
extern FILE *yyin;
extern int line_count;
FILE *logout  = fopen("1605070_log.txt","w");
// FILE *logout_er  = fopen("1605070_loger.txt","w");
FILE *codeout = fopen("1605070_code.asm", "w");

extern int total_error;

SymbolTable *table = new SymbolTable(30, logout);
vector<pair<string, string>> parameters;
bool parameterSaved = false;
string functionReturnType = "";
bool hasReturnType = false;
bool matchFunction(vector<string> &, vector<string> &);
vector<string> split_token(const string& s, const string& delimeters);
unordered_set<string> variable_set;
vector<string> tempVar_set;
string current_function_name = "";

int labelCount = 0;
int tempCount = 0;

string newLabel();
string newTempVar();
string initialized_code = ".model small\n.stack 100h\n.data\n";
string variable_defined = "";
string function_defined = "";
string main_defined = "";
string funct_call_var();
int totalArguments = 0;
int max_parameters = 0;

void yyerror(const char *s)
{
	//write your code
	fprintf(logout, "Error at line %d : %s\n\n", line_count, s);
}

%}

%error-verbose

%union {
	SymbolInfo* info;
}

%token IF ELSE FOR WHILE  ASSIGNOP COMMA INCOP DECOP FLOAT CHAR INT LCURL LPAREN LTHIRD  NOT PRINTLN RCURL RETURN SEMICOLON RTHIRD RPAREN VOID DOUBLE

%token <info> ADDOP CONST_FLOAT CONST_INT ID LOGICOP MULOP RELOP

%type <info> program unit var_declaration func_declaration func_definition type_specifier parameter_list compound_statement statements declaration_list statement expression_statement expression variable logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments function_first_part_1 function_first_part_2 left_curl

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start : program {
	// //fprintf(logout_er, "At line no: %d start : program\n", line_count);
	//fprintf(logout_er, "\t\t Symbol Table:\n\n");
	// table->printAll();
	if(total_error == 0){
		// peephole optimization
		vector<string> check1 = split_token(main_defined, "\n");
		vector<string> check2 = split_token(function_defined, "\n");
		// unordered_set<string> variable_set;
		bool previous_hole = false;

		string main_defined_new = "";
		string function_defined_new = "";
		string variable_defined_new = "";
		string test1 = check1[0];
		string test2;
		vector<string> tokens1 = split_token(test1, " ,");
		vector<string> tokens2;
		for(int i = 1; i < check1.size()-4; i++){
			test2 = check1[i];
			tokens2 = split_token(test2, " ,");
			if(tokens1.size() == 3 && tokens2.size() == 3 && tokens1[0] == "mov" && tokens2[0] == "mov" && tokens1[1] == tokens2[2] && tokens1[2] == tokens2[1] ){
				if((tokens1[1][0] == 't' || tokens1[2][0] == 't')){
					variable_set.erase(tokens1[1]+"\tdw\t'?'\n");
					variable_set.erase(tokens1[2]+"\tdw\t'?'\n");
				} else if(tokens1[1][0] != 't'){
					main_defined_new += test1 + "\n";
				}
				previous_hole = true;
			} else{
				if(!previous_hole) main_defined_new += test1 + "\n";
				previous_hole = false;
			}
			test1 = test2 ;
			tokens1 = tokens2;
		}
		main_defined_new += "mov ah, 4ch\nint 21h\n";

		test1 = check2[0];
		tokens1 = split_token(test1, " ,");
		tokens2;

		for(int i = 1; i < check2.size(); i++){
			test2 = check2[i];
			tokens2 = split_token(test2, " ,");
			if(tokens1.size() == 3 && tokens2.size() == 3 && tokens1[0] == "mov" && tokens2[0] == "mov" && tokens1[1] == tokens2[2] && tokens1[2] == tokens2[1]){
				if((tokens1[1][0] == 't' || tokens1[2][0] == 't')){
					variable_set.erase(tokens1[1]+"\tdw\t'?'\n");
					variable_set.erase(tokens1[2]+"\tdw\t'?'\n");
				} else if(tokens1[1][0] != 't'){
					function_defined_new += test1 + "\n";
				}
				previous_hole = true;
			}
			 else if(tokens1.size() == 2 && (tokens1[0] == "push" || tokens1[0] == "pop") && tokens1[1][0] == 't' && variable_set.find(tokens1[1]+"\tdw\t'?'\n") == variable_set.end()){

			} else{
				if(!previous_hole) function_defined_new += test1 + "\n";
				previous_hole = false;
			}
			
			test1 = test2 ;
			tokens1 = tokens2;
		}

		for(string var : variable_set){
			variable_defined_new += var;
		}

		string print_func = "println proc\npush ax\npush bx\npush cx\npush dx\nor ax, ax\njge @end_if\npush ax\nmov dl, '-'\nmov ah, 2\nint 21h\npop ax\nneg ax\n@end_if:\nxor cx, cx\nmov bx, 10d\n@repeat1:\nxor dx, dx\ndiv bx\npush dx\ninc cx\nor ax, ax\njne @repeat1\nmov ah, 2\n@print_loop:\npop dx\nor dl, 30h\nint 21h\nloop @print_loop\nmov ah, 2\nmov dl, 0dh\nint 21h\nmov dl, 0ah\nint 21h\n\npop dx\npop cx\npop bx\npop ax\nret\nprintln endp\n";

		fprintf(codeout, "%s%s",initialized_code.c_str(), variable_defined_new.c_str());
		for(int i = 1; i <= max_parameters; i++){
			fprintf(codeout, "%s\tdw\t'?'\n", funct_call_var().c_str());
		}
		fprintf(codeout, "\n%smain\tendp\n\n%s\n%s\tend main", main_defined_new.c_str(), function_defined_new.c_str(), print_func.c_str());
	}
	delete $1;
}
	;

program : program unit {
	//fprintf(logout_er, "At line no: %d program : program unit\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() + $2->getName();
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	delete $1;
	delete $2;
}
	| unit {
		//fprintf(logout_er, "At line no: %d program : unit\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName();
		$$->setName(str);
		//fprintf(logout_er, "\n%s\n\n", str.c_str());
		delete $1;
 	}
	;

unit : var_declaration {
	//fprintf(logout_er, "At line no: %d unit : var_declaration\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() ;
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	delete $1;
}
     | func_declaration {
		 //fprintf(logout_er, "At line no: %d unit : func_declaration\n", line_count);
		 $$ = new SymbolInfo();
		 string str = $1->getName();
		 $$->setName(str);
		 //fprintf(logout_er, "\n%s\n\n", str.c_str());

		 delete $1;
	 }
     | func_definition {
		 //fprintf(logout_er, "At line no: %d unit : func_definition\n", line_count);
		 $$ = new SymbolInfo();
		 string str = $1->getName();
		 $$->setName(str);
		 //fprintf(logout_er, "\n%s\n\n", str.c_str());

		 delete $1;
	 }
     ;

func_declaration : function_first_part_1 SEMICOLON {
	if(parameterSaved){
		parameters.clear();
		parameterSaved = false;
	}
	//fprintf(logout_er, "At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() + ";\n";
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	delete $1;
}
		| function_first_part_2 SEMICOLON {
			//fprintf(logout_er, "At line no: %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n", line_count);
			$$ = new SymbolInfo();
			string str = $1->getName() + ";\n";
			$$->setName(str);
			//fprintf(logout_er, "\n%s\n\n", str.c_str());

			delete $1;
		}
		;

func_definition : function_first_part_1 compound_statement {
	//fprintf(logout_er, "At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() + " " + $2->getName();
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	SymbolInfo* symbol = table->lookUp($1->getType());
	if(symbol){
		if(symbol->isDefined){
			fprintf(logout, "Error at line %s : redefinition of '%s'\n\n", $1->parameterList[0].c_str(), $1->getType().c_str());
			total_error++;
		} else {
			symbol->isDefined = true;
			if(!hasReturnType && symbol->parameterList[0] != "void") {
				fprintf(logout, "Error at line  %d : function body has no return statement\n\n", line_count);
				total_error++;
			} else {
				hasReturnType = false;
				$$->code += $1->getType()+"\tproc\n";
				/* for(int i = 1; i <= stoi($1->getCategory()); i++ ){
					$$->code += "push f"+to_string(i)+"\n";
				} */
				$$->code += $2->code;
				/* for(int i = stoi($1->getCategory()); i >= 1; i-- ){
					$$->code += "pop f"+to_string(i)+"\n";
				} */
				$$->code += $1->getType()+"\tendp\n\n";
				function_defined += $$->code;
			}
		}
	}

	delete $1;
	delete $2;
}
		| function_first_part_2  compound_statement {
			//fprintf(logout_er, "At line no: %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n", line_count);
			$$ = new SymbolInfo();
			string str = $1->getName() + " " + $2->getName();
			$$->setName(str);
			//fprintf(logout_er, "\n%s\n\n", str.c_str());
			SymbolInfo* symbol = table->lookUp($1->getType());
			if(symbol){
				if(symbol->isDefined){
				fprintf(logout, "Error at line %s : redefinition of '%s'\n\n", $1->parameterList[0].c_str(), $1->getType().c_str());
				total_error++;
				} else {
					symbol->isDefined = true;
					if(!hasReturnType && symbol->parameterList[0] != "void") {
						fprintf(logout, "Error at line  %d : function body has no return statement\n\n", line_count);
						total_error++;
					} else {
						hasReturnType = false;

						if($1->getType() == "main"){
							main_defined += "main\tproc\nmov ax, @data\nmov ds, ax\n" + $2->code + "main\tendp\n\n";
						} else {
							function_defined += $1->getType() + "\tproc\n"+$2->code+$1->getType()+ "\tendp\n\n";
						}
					}
				}
			}

			delete $1;
			delete $2;
		}
 		;

function_first_part_1 : type_specifier ID LPAREN parameter_list RPAREN {

	$$ = new SymbolInfo();
	string str = $1->getName() + " " + $2->getName() + "(" + $4->getName() + ")";
	$$->setName(str);
	parameterSaved = true;
	$$->setCategory(to_string($4->parameterList.size()));

	SymbolInfo* foundSymbol = table->lookUp($2->getName());

	if(foundSymbol){
		vector<string> list = foundSymbol->parameterList;
		vector<string> para;
		para.push_back($1->getName());
		para.insert(para.end(), $4->parameterList.begin(), $4->parameterList.end());
		para.push_back("function");
		if(list[list.size() - 1] == "function"){
			if(!matchFunction(list, para)){
				fprintf(logout, "Erorr at line %d : conflicting types for  '%s'\n\n", line_count, $2->getName().c_str());
				total_error++;
				$$->setName("error");
			} else {
				functionReturnType = $1->getName();
				$$->setType($2->getName());
				$$->parameterList.push_back(to_string(line_count));
			}
		}
		else {
			fprintf(logout, "Erorr at line %d : '%s' redeclared as different kind of symbol\n\n", line_count, $2->getName().c_str());
			total_error++;
			$$->setName("error");
		}
	} else {

		SymbolInfo* symbol = new SymbolInfo($2->getName(), "ID");
		symbol->parameterList.push_back($1->getName());
		symbol->parameterList.insert(symbol->parameterList.end(), $4->parameterList.begin(), $4->parameterList.end());
		symbol->parameterList.push_back("function");
		functionReturnType = $1->getName();
		$$->setType($2->getName());
		current_function_name = $2->getName();

		$$->parameterList.push_back(to_string(line_count));
		table->insert(symbol);
	}

	delete $1;
	delete $2;
	delete $4;
}
			;

function_first_part_2:  type_specifier ID LPAREN RPAREN {

	$$ = new SymbolInfo();
	string str = $1->getName() + " " + $2->getName() + "()";
	$$->setName(str);

	SymbolInfo* foundSymbol = table->lookUp($2->getName());

	if(foundSymbol){
		vector<string> list = foundSymbol->parameterList;
		if(list[list.size() - 1] == "function"){
			if(list.size() != 2){
				fprintf(logout, "Erorr at line %d : conflicting types for  '%s'\n\n", line_count, $2->getName().c_str());
				$$->setName("error");
				total_error++;
			} else {
				functionReturnType = $1->getName();
				$$->setType($2->getName());
				$$->parameterList.push_back(to_string(line_count));
			}
		}
		else {
			fprintf(logout, "Erorr at line %d : '%s' redeclared as different kind of symbol\n\n", line_count, $2->getName().c_str());
			$$->setName("error");
			total_error++;
		}

	} else {
		SymbolInfo* symbol = new SymbolInfo($2->getName(), "ID");
		symbol->parameterList.push_back($1->getName());
		symbol->parameterList.push_back("function");
		functionReturnType = $1->getName();
		$$->setType($2->getName());
		current_function_name = $2->getName();
		$$->parameterList.push_back(to_string(line_count));

		table->insert(symbol);
	}

	delete $1;
	delete $2;

}
					;


parameter_list  : parameter_list COMMA type_specifier ID {
	//fprintf(logout_er, "At line no: %d parameter_list  : parameter_list COMMA type_specifier ID\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() + ", " + $3->getName() + " "+ $4->getName();
	$$->setName(str);
	$$->parameterList.insert($$->parameterList.end(), $1->parameterList.begin(), $1->parameterList.end());
	$$->parameterList.push_back($3->getName());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	bool duplicateName = false;
	for(int i = 0; i < parameters.size(); i++) {
		if(parameters[i].first == $4->getName()){
			duplicateName = true;
			break;
		}
	}
	if(duplicateName) {
		fprintf(logout, "Error at line %d : multiple definition of '%s'\n\n", line_count, $4->getName().c_str());
	} else parameters.push_back(make_pair($4->getName(), $3->getName()));

	delete $1;
	delete $3;
	delete $4;
}
		| parameter_list COMMA type_specifier {
			//fprintf(logout_er, "At line no: %d parameter_list  : parameter_list COMMA type_specifier\n", line_count);
			$$ = new SymbolInfo();
			string str = $1->getName() + ", " + $3->getName();
			$$->setName(str);
			$$->parameterList.insert($$->parameterList.end(), $1->parameterList.begin(), $1->parameterList.end());
			$$->parameterList.push_back($3->getName());
			//fprintf(logout_er, "\n%s\n\n", str.c_str());
			delete $1;
			delete $3;
		}
 		| type_specifier ID {
			 //fprintf(logout_er, "At line no: %d parameter_list  : type_specifier ID\n", line_count);
			 $$ = new SymbolInfo();
			 string str = $1->getName() + " " + $2->getName();
			 $$->setName(str);
			 $$->parameterList.push_back($1->getName());
			 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 parameters.push_back(make_pair($2->getName(), $1->getName()));

			 delete $1;
			 delete $2;
		 }
		| type_specifier {
			//fprintf(logout_er, "At line no: %d parameter_list  : type_specifier\n", line_count);
			$$ = new SymbolInfo();
			string str = $1->getName();
			$$->setName(str);
			$$->parameterList.push_back($1->getName());
			//fprintf(logout_er, "\n%s\n\n", str.c_str());
			delete $1;
		}
 		;


compound_statement : left_curl statements RCURL {
	//fprintf(logout_er, "At line no: %d compound_statement : LCURL statements RCURL\n", line_count);
	$$ = new SymbolInfo();
	string str = "{\n" + $2->getName() + "}\n";
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	// table->printAll();
	table->exitScope();

	$$->code += $2->code;

	delete $2;
}
 		    | left_curl RCURL {
				 //fprintf(logout_er, "At line no: %d compound_statement : LCURL RCURL\n", line_count);
				 $$ = new SymbolInfo();
			 	 string str = "{\n}\n";
			 	 $$->setName(str);
			 	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

				//  table->printAll();
				 table->exitScope();
			 }
 		    ;

left_curl : LCURL {
	table->enterScope();

	if(parameters.size() != 0){
		tempVar_set.clear();

	}

	for(int i = 0; i < parameters.size(); i++){
		SymbolInfo* symbol = new SymbolInfo(parameters[i].first, "ID");
		symbol->parameterList.push_back(parameters[i].second);
		symbol->parameterList.push_back("normal");
		table->insert(symbol);
		int temp = i + 1;
		string var = "f"+to_string(temp);
		symbol->setSymbol(var);
	}
	if(parameters.size() > max_parameters) max_parameters = parameters.size();

	if(parameters.size() != 0){
		parameters.clear();
	}
}
		;

var_declaration : type_specifier declaration_list SEMICOLON {
		//fprintf(logout_er, "At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName() + " " + $2->getName() + ";\n";
		if($1->getName() == "void") {
			$$->setName("error");
			fprintf(logout, "Error at line %d : variable declared void\n\n", line_count);
			total_error++;
		} else {
			$$->setName(str);
			//fprintf(logout_er, "\n%s\n\n", str.c_str());

			stringstream tokenize($2->getName());
			string temp;

			while(getline(tokenize, temp, ',')){
				int found = temp.find("[");
				if(found == -1) {
					SymbolInfo* got = table->lookUpCurrent(temp);
					if(got) {
						fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, temp.c_str());
						total_error++;
					} else {
						SymbolInfo* symbol = new SymbolInfo(temp, "ID");
						symbol->parameterList.push_back($1->getName());
						symbol->parameterList.push_back("normal");
						table->insert(symbol);
						variable_defined += symbol->getSymbol() + "\tdw\t'?'\n";
						variable_set.insert(symbol->getSymbol()+"\tdw\t'?'\n");

					}
				}
				else{
					int found2 = temp.find("]", found+1);
					string size = temp.substr(found+1, found2-found-1);
					string content = temp.substr(0,found);
					bool got = table->lookUpCurrent(content);
					if(got) {
						fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, content.c_str());
						total_error++;
					} else {
						SymbolInfo* symbol = new SymbolInfo(content, "ID");
						symbol->parameterList.push_back($1->getName());
						symbol->parameterList.push_back(size);
						symbol->parameterList.push_back("array");
						table->insert(symbol);
						variable_defined += symbol->getSymbol() + "\tdw\t" + size + " dup (?)\n";
						variable_set.insert(symbol->getSymbol() + "\tdw\t"+ size + " dup (?)\n");
					}
				}
			}
		}

		delete $1;
		delete $2;
	}
	| type_specifier declaration_list error {
		//fprintf(logout_er, "';' not provided after variable declaration\n\n");

		//fprintf(logout_er, "At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName() + " " + $2->getName() + "; // corrected\n";
		$$->setName(str);
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		stringstream tokenize($2->getName());
		string temp;

		while(getline(tokenize, temp, ',')){
			int found = temp.find("[");
			if(found == -1) {
				bool got = table->lookUpCurrent(temp);
				if(got) {
					fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, temp.c_str());
					total_error++;
				} else {
					SymbolInfo* symbol = new SymbolInfo(temp, "ID");
					symbol->parameterList.push_back($1->getName());
					symbol->parameterList.push_back("normal");
					table->insert(symbol);
				}
			}
			else{
				int found2 = temp.find("]", found+1);
				string size = temp.substr(found+1, found2-found-1);
				string content = temp.substr(0,found);
				bool got = table->lookUpCurrent(content);
				if(got) {
					fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, content.c_str());
					total_error++;
				} else {
					SymbolInfo* symbol = new SymbolInfo(content, "ID");
					symbol->parameterList.push_back($1->getName());
					symbol->parameterList.push_back(size);
					symbol->parameterList.push_back("array");
					table->insert(symbol);
				}
			}
		}

		delete $1;
		delete $2;

	}

 		 ;

type_specifier : INT {
	//fprintf(logout_er, "At line no: %d type_specifier : INT\n", line_count);
	$$ = new SymbolInfo();
	$$->setName("int");
	//fprintf(logout_er, "\nint\n\n");
}
 		| FLOAT {
			 //fprintf(logout_er, "At line no: %d type_specifier	: FLOAT\n", line_count);
			 $$ = new SymbolInfo();
			 $$->setName("float");
			 //fprintf(logout_er, "\nfloat\n\n");
		 }
 		| VOID {
			 //fprintf(logout_er, "At line no: %d type_specifier : VOID\n", line_count);
			 $$ = new SymbolInfo();
			 $$->setName("void");
			 //fprintf(logout_er, "\nvoid\n\n");
		 }
		| CHAR {
			//fprintf(logout_er, "At line no: %d type_specifier : CHAR\n", line_count);
			$$ = new SymbolInfo();
			$$->setName("char");
			//fprintf(logout_er, "\nchar\n\n");
		}
 		;

declaration_list : declaration_list COMMA ID {
	//fprintf(logout_er, "At line no: %d declaration_list : declaration_list COMMA ID\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() + "," + $3->getName();
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	delete $1;
	delete $3;
}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
			   //fprintf(logout_er, "At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n", line_count);
			   $$ = new SymbolInfo();
			   string str = $1->getName() + "," + $3->getName() + "[" + $5->getName() + "]";
			   $$->setName(str);
			   //fprintf(logout_er, "\n%s\n\n", str.c_str());

			   delete $1;
			   delete $3;
			   delete $5;
		   }
 		  | ID {
			   //fprintf(logout_er, "At line no: %d declaration_list : ID\n", line_count);
			   $$ = new SymbolInfo();
			   string str = $1->getName();
			   $$->setName(str);
			   //fprintf(logout_er, "\n%s\n\n", str.c_str());
			   delete $1;

		   }
 		  | ID LTHIRD CONST_INT RTHIRD {
			   //fprintf(logout_er, "At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n", line_count);
			   $$ = new SymbolInfo();
			   string str = $1->getName() + "[" + $3->getName() + "]";
			   $$->setName(str);
			   //fprintf(logout_er, "\n%s\n\n", str.c_str());

			   delete $1;
			   delete $3;
		   }
 		  ;

statements : statement {
	//fprintf(logout_er, "At line no: %d statements : statement\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code = $1->code;

	delete $1;
}
	   | statements statement {
		   //fprintf(logout_er, "At line no: %d statements : statements statement\n", line_count);
		   $$ = new SymbolInfo();
		   string str = $1->getName()+ $2->getName();
		   $$->setName(str);
		   //fprintf(logout_er, "\n%s\n\n", str.c_str());

		   $$->code = $1->code + $2->code;

		   delete $1;
		   delete $2;
	   }
	   ;


statement : var_declaration {
	//fprintf(logout_er, "At line no: %d statement : var_declaration\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);

	$$->code = $1->code;

	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	delete $1;
}
	  | expression_statement {
		  //fprintf(logout_er, "At line no: %d statement : expression_statement\n", line_count);
		  $$ = new SymbolInfo();
		  string str = $1->getName() + "\n";
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  $$->code = $1->code;

		  delete $1;
	  }
	  | compound_statement {
		  //fprintf(logout_er, "At line no: %d statement : compound_statement\n", line_count);
		  $$ = new SymbolInfo();
		  string str = $1->getName();
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  $$->code = $1->code;

		  delete $1;
	  }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
		  //fprintf(logout_er, "At line no: %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "for(" + $3->getName() + $4->getName() + $5->getName() +") " + $7->getName();
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  $$->code = $3->code;
		  string label1 = newLabel();
		  string label2 = newLabel();
		  $$->code += label1 + ":\n";
		  $$->code += $4->code;
		  $$->code += "mov ax, "+$4->getSymbol()+"\n";
		  $$->code += "cmp ax, 0\n";
		  $$->code += "jz "+label2+"\n";
		  $$->code += $7->code + $5->code + "jmp "+label1+"\n";
		  $$->code += label2+":\n";

		  delete $3;
		  delete $4;
		  delete $5;
		  delete $7;
	  }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
		  //fprintf(logout_er, "At line no: %d statement : IF LPAREN expression RPAREN statement\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "if(" + $3->getName() + ") " + $5->getName();
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  $$->code = $3->code;
		  string label1 = newLabel();
		  $$->code += "mov ax, "+$3->getSymbol()+"\n";
		  $$->code += "cmp ax, 0\n";
		  $$->code += "je "+label1+"\n";
		  $$->code += $5->code + label1+":\n";

		  delete $3;
		  delete $5;
	  }
	  | IF LPAREN expression RPAREN statement ELSE statement {
		  //fprintf(logout_er, "At line no: %d statement : IF LPAREN expression RPAREN statement ELSE statement\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "if(" + $3->getName() + ") " + $5->getName() + "else " + $7->getName();
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  $$->code = $3->code;
		  string label1 = newLabel();
		  $$->code += "mov ax, "+$3->getSymbol()+"\n";
		  $$->code += "cmp ax, 0\n";
		  $$->code += "je "+label1+"\n";
		  $$->code += $5->code + label1+":\n";
		  $$->code += $7->code;

		  delete $3;
		  delete $5;
		  delete $7;
	  }
	  | WHILE LPAREN expression RPAREN statement {
		  //fprintf(logout_er, "At line no: %d statement : WHILE LPAREN expression RPAREN statement\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "while(" + $3->getName() + ") " + $5->getName();
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  string label1 = newLabel();
		  string label2 = newLabel();
		  $$->code += label1 + ":\n"+$3->code;
		  $$->code += "mov ax, "+$3->getSymbol()+"\n";
		  $$->code += "cmp ax, 0\n";
		  $$->code += "jz "+label2+"\n";
		  $$->code += $5->code + "jmp "+label1+"\n";
		  $$->code += label2+":\n";

		  delete $3;
		  delete $5;
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON {
		  //fprintf(logout_er, "At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "println(" + $3->getName() + ")" +";\n";
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  SymbolInfo* symbol = table->lookUp($3->getName());
		  if(symbol && symbol->getType() == "ID"){
		  	$$->code += "mov ax, "+symbol->getSymbol()+"\ncall println\n";
		  } else{
			  fprintf(logout, "Error at line %d : not declared '%s'\n\n", line_count, $3->getName().c_str());
		  }

		  delete $3;
	  }
	  | PRINTLN LPAREN ID RPAREN error {
		  //fprintf(logout_er, "';' not provided\n\n");
		  //fprintf(logout_er, "At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "println(" + $3->getName() + ")" +"; // corrected\n";
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  delete $3;
	  }
	  | RETURN expression SEMICOLON {
		  //fprintf(logout_er, "At line no: %d statement : RETURN expression SEMICOLON\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "return " + $2->getName() + ";\n";
		  if(functionReturnType != $2->getType() && $2->getType() != "error"){
			  fprintf(logout, "Error at line %d : function return type not matched(have '%s' and '%s')\n\n", line_count, functionReturnType.c_str(), $2->getType().c_str());
		  }
		  hasReturnType = true;
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  $$->code += $2->code;
		  $$->code += "mov ax, "+$2->getSymbol()+"\nret\n";

		  delete $2;
	  }
	  | RETURN expression error {
		  //fprintf(logout_er, "';' not provided\n\n");
		  //fprintf(logout_er, "At line no: %d statement : RETURN expression SEMICOLON\n", line_count);
		  $$ = new SymbolInfo();
		  string str = "return " + $2->getName() + "; // corrected\n";
		  $$->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());
		  delete $2;
	  }
	  ;

expression_statement : SEMICOLON {
	//fprintf(logout_er, "At line no: %d expression_statement : SEMICOLON\n", line_count);
	$$ = new SymbolInfo();
	string str = ";";
	$$->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
}
			| expression SEMICOLON {
				//fprintf(logout_er, "At line no: %d expression_statement : expression SEMICOLON\n", line_count);
				$$ = new SymbolInfo();
		  		string str = $1->getName() + ";";
		  		$$->setName(str);
		  		//fprintf(logout_er, "\n%s\n\n", str.c_str());

				$$->code = $1->code;
				$$->setSymbol($1->getSymbol());

				delete $1;
			}
			;

variable : ID {
	//fprintf(logout_er, "At line no: %d variable : ID\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	SymbolInfo* symbol = table->lookUp($1->getName());
	if(symbol){
		if(symbol->parameterList[symbol->parameterList.size()-1] == "normal") {
			$$->setType(symbol->parameterList[0]);
		}
		else{
			$$->setType("error");
			fprintf(logout, "Error at line %d : lvalue required\n\n", line_count);
			total_error++;
		}
	} else{
		$$->setType("error");
		total_error++;
		fprintf(logout, "Error at line %d : '%s' undeclared\n\n", line_count, $1->getName().c_str());
	}
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->setCategory("notarray");
	$$->setSymbol(symbol->getSymbol());

	delete $1;
}
	 | ID LTHIRD expression RTHIRD {
		 //fprintf(logout_er, "At line no: %d variable : ID LTHIRD expression RTHIRD\n", line_count);
		 $$ = new SymbolInfo();
		 string str = $1->getName() + "[" + $3->getName() + "]";
		 $$->setName(str);
		 //fprintf(logout_er, "\n%s\n\n", str.c_str());
		 if($3->getType() != "int") {
			 $$->setType("error");
			 fprintf(logout, "Error at line %d : array subscript is not an integer (have '%s')\n\n", line_count, $3->getType().c_str());
			 total_error++;
		 } else {
			SymbolInfo* symbol = table->lookUp($1->getName());
			if(symbol){
				if(symbol->parameterList[symbol->parameterList.size()-1] == "array") {
					$$->setType(symbol->parameterList[0]);
					string size = symbol->parameterList[1];
					if(stoi($3->getName()) >= stoi(size)){
						fprintf(logout, "Error at line %d : Array index out of bound (array size '%s', used index '%s')\n\n", line_count, size.c_str(), $3->getName().c_str());
						total_error++;
					}

					$$->setCategory("array");
		 			$$->setSymbol(symbol->getSymbol());
		 			$$->code += $3->code + "mov bx, "+$3->getSymbol()+"\nsll bx, 2\n";
				}
				else{
					$$->setType("error");
					fprintf(logout, "Error at line %d : subscripted value is not array\n\n", line_count);
					total_error++;
				}
			}   else{
					$$->setType("error");
					fprintf(logout, "Error at line %d : undeclared\n\n", line_count);
					total_error++;
			}
		 }

		 delete $1;
		 delete $3;
	 }
	 ;

expression : logic_expression {
	//fprintf(logout_er, "At line no: %d expression : logic_expression\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	$$->setType($1->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code += $1->code;
	$$->setSymbol($1->getSymbol());

	delete $1;
}
	   | variable ASSIGNOP logic_expression {
		   //fprintf(logout_er, "At line no: %d expression : variable ASSIGNOP logic_expression\n", line_count);
		   $$ = new SymbolInfo();
		   string str = $1->getName() + " = " + $3->getName();
		   $$->setName(str);
		   $$->setType($1->getType());

		   if($1->getType() != $3->getType()) {
			   if($3->getType() == "void") {
					fprintf(logout, "Error at line %d : 'void' type cannot be assigned\n\n", line_count);
					total_error++;
			   } else if($3->getType() != "error" && $1->getType() != "error") {
			   		fprintf(logout, "Error at line %d : operands types mismatch (have '%s' and '%s' )\n\n", line_count, $1->getType().c_str(), $3->getType().c_str());
					total_error++;
			   }
			   $$->setType("error");
		   }

		   //fprintf(logout_er, "\n%s\n\n", str.c_str());

		   $$->code = $3->code + $1->code;
		   $$->setSymbol($3->getSymbol());
		   $$->code += "mov ax, "+$3->getSymbol()+"\n";
		   if($1->getCategory() == "notarray"){
			   $$->code += "mov "+$1->getSymbol()+", ax\n";
		   } else {
			   $$->code  += "mov "+$1->getSymbol()+"[bx], ax\n";
		   }

		   delete $1;
		   delete $3;
	   }
	   ;

logic_expression : rel_expression {
	//fprintf(logout_er, "At line no: %d logic_expression : rel_expression\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	$$->setType($1->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code += $1->code;
	$$->setSymbol($1->getSymbol());

	delete $1;
}
		 | rel_expression LOGICOP rel_expression {
			 //fprintf(logout_er, "At line no: %d logic_expression : rel_expression LOGICOP rel_expression\n", line_count);
			 $$ = new SymbolInfo();
		  	 string str = $1->getName() + " " + $2->getName() + " " + $3->getName();
		  	 $$->setName(str);
			 $$->setType("int");
		  	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 $$->code += $1->code + $3->code;
			 $$->code += "mov ax, "+$1->getSymbol()+"\n";
			$$->code += "cmp ax, 0\n";
			string tempVar = newTempVar();
			tempVar_set.push_back(tempVar);
			string label1 = newLabel();
			string label2 = newLabel();
			variable_defined += tempVar + "\tdw\t'?'\n";
			variable_set.insert(tempVar + "\tdw\t'?'\n");

			 if($2->getName() == "&&"){
				 $$->code += "jz "+label1+"\n";
				 $$->code += "mov ax, "+$3->getSymbol()+"\n";
				 $$->code += "cmp ax, 0\n";
				 $$->code += "jz "+label1+"\n";
				 $$->code += "mov "+tempVar+", 1\njmp "+label2+"\n";
				 $$->code += label1+":\n"+"mov "+tempVar+", 0\n";
				 $$->code += label2+":\n";
			 } else{
				 $$->code += "jnz "+label1+"\n";
				 $$->code += "mov ax, "+$3->getSymbol()+"\n";
				 $$->code += "cmp ax, 0\n";
				 $$->code += "jnz "+label1+"\n";
				 $$->code += "mov "+tempVar+", 0\njmp "+label2+"\n";
				 $$->code += label1+":\n"+"mov "+tempVar+", 1\n";
				 $$->code += label2+":\n";
			 }
			 $$->setSymbol(tempVar);

			 delete $1;
			 delete $2;
			 delete $3;
		 }
		 ;

rel_expression	: simple_expression {
	//fprintf(logout_er, "At line no: %d rel_expression	: simple_expression\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	$$->setType($1->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code += $1->code;
	$$->setSymbol($1->getSymbol());

	delete $1;
}
		| simple_expression RELOP simple_expression {
			//fprintf(logout_er, "At line no: %d rel_expression	: simple_expression RELOP simple_expression\n", line_count);
			$$ = new SymbolInfo();
		  	string str = $1->getName() + " " + $2->getName() + " " + $3->getName();
		  	$$->setName(str);
			$$->setType("int");
		  	//fprintf(logout_er, "\n%s\n\n", str.c_str());

			$$->code += $1->code + $3->code;
			$$->code += "mov ax, " + $1->getSymbol()+"\n";
			$$->code += "cmp ax, " + $3->getSymbol()+"\n";

			string tempVar = newTempVar();
			tempVar_set.push_back(tempVar);
			variable_defined += tempVar + "\tdw\t'?'\n";
			variable_set.insert(tempVar + "\tdw\t'?'\n");

			string label1 = newLabel();
			string label2 = newLabel();

			if($2->getName() == "<"){
				$$->code += "jl " + label1 + "\n";

			} else if($2->getName() == "<="){
				$$->code += "jle " + label1 + "\n";
			} else if($2->getName() == ">"){
				$$->code += "jg " + label1 + "\n";
			} else if($2->getName() == ">="){
				$$->code += "jge " + label1 + "\n";
			} else if($2->getName() == "=="){
				$$->code += "je " + label1 + "\n";
			} else if($2->getName() == "!="){
				$$->code += "jne " + label1 + "\n";
			}
			$$->code += "mov "+tempVar+", 0\n";
			$$->code += "jmp "+label2+"\n";
			$$->code += label1+":\nmov "+tempVar+", 1\n";
			$$->code += label2+":\n";
			$$->setSymbol(tempVar);

			delete $1;
			delete $2;
			delete $3;
		}
		;

simple_expression : term {
	//fprintf(logout_er, "At line no: %d simple_expression : term\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	$$->setType($1->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code += $1->code;
	$$->setSymbol($1->getSymbol());

	delete $1;
}
		  | simple_expression ADDOP term {
			  //fprintf(logout_er, "At line no: %d simple_expression : simple_expression ADDOP term\n", line_count);
			  $$ = new SymbolInfo();
		  	  string str = $1->getName() + " " + $2->getName() + " " + $3->getName();
		  	  $$->setName(str);

			  if($1->getType() == "float" || $2->getType() == "float")	$$->setType("float");
			  else $$->setType("int");

		  	  //fprintf(logout_er, "\n%s\n\n", str.c_str());

			  $$->code += $1->code + $3->code;
			  $$->code += "mov ax, "+$1->getSymbol()+"\n";
			  string tempVar = newTempVar();
			  tempVar_set.push_back(tempVar);
			  variable_defined += tempVar + "\tdw\t'?'\n";
			  variable_set.insert(tempVar + "\tdw\t'?'\n");

			  if($2->getName() == "+"){
				  $$->code += "add ax, "+$3->getSymbol()+"\n";
			  } else {
				  $$->code += "sub ax, "+$3->getSymbol()+"\n";
			  }
			  $$->code += "mov "+tempVar + ", ax\n";
			  $$->setSymbol(tempVar);

			  delete $1;
			  delete $2;
			  delete $3;
		  }
		  ;

term :	unary_expression {
	//fprintf(logout_er, "At line no: %d term : unary_expression\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	$$->setType($1->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code += $1->code;
	$$->setSymbol($1->getSymbol());

	delete $1;
}
     |  term MULOP unary_expression {
		 //fprintf(logout_er, "At line no: %d term : term MULOP unary_expression\n", line_count);
		 $$ = new SymbolInfo();
		 string str = $1->getName() + $2->getName() + $3->getName();
		 $$->setName(str);

		 if($1->getType() == "float" || $3->getType() == "float")	$$->setType("float");
		 else $$->setType("int");

		 if($2->getName() == "%" && ($1->getType() == "float" || $3->getType() == "float")) {
			$$->setType("error");
			fprintf(logout, "Error at line %d : invalid operands to binary % (have '%s' and '%s')\n\n", line_count, $1->getType().c_str(), $3->getType().c_str());
			total_error++;
		 }

		 //fprintf(logout_er, "\n%s\n\n", str.c_str());

		 $$->code = $1->code + $3->code;
		 $$->code += "mov ax, "+$1->getSymbol()+"\n";
		 $$->code += "mov bx, "+$3->getSymbol()+"\n";
		 string tempVar = newTempVar();
		 tempVar_set.push_back(tempVar);
		 variable_defined += tempVar + "\tdw\t'?'\n";
		 variable_set.insert(tempVar + "\tdw\t'?'\n");
		 if($2->getName() == "*"){
			 $$->code += "imul bx\n";
			 $$->code += "mov "+tempVar+", ax\n";
		 } else if($2->getName() == "/"){
			 //  $$->code += "xor dx, dx\n";
			 $$->code += "cwd\n";
			 $$->code += "idiv bx\nmov "+tempVar+", ax\n";
		 } else{
			//  $$->code += "xor dx, dx\n";
			 $$->code += "cwd\n";
			 $$->code += "idiv bx\nmov "+tempVar+", dx\n";
		 }
		 $$->setSymbol(tempVar);

		 delete $1;
		 delete $2;
		 delete $3;
	 }
     ;

unary_expression : ADDOP unary_expression {
	//fprintf(logout_er, "At line no: %d unary_expression : ADDOP unary_expression\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() + $2->getName();
	$$->setName(str);
	$$->setType($2->getType());

	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code += $2->code;
	string tempVar = newTempVar();
	tempVar_set.push_back(tempVar);
	variable_defined += tempVar + "\tdw\t'?'\n";
	variable_set.insert(tempVar + "\tdw\t'?'\n");
	$$->code += "mov ax, "+$2->getSymbol()+"\n";
	$$->code += "mov "+tempVar+", ax\n";

	if($1->getName() == "-"){
		$$->code += "neg "+tempVar+"\n";
	}
	$$->setSymbol(tempVar);

	delete $1;
	delete $2;
}
		 | NOT unary_expression {
			 //fprintf(logout_er, "At line no: %d unary_expression : NOT unary_expression\n", line_count);
			 $$ = new SymbolInfo();
		  	 string str = "!" + $2->getName();
		  	 $$->setName(str);
			 $$->setType("int");
		  	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 $$->code += $2->code;
			 string tempVar = newTempVar();
			 tempVar_set.push_back(tempVar);
			 $$->code += "mov ax, "+$2->getSymbol()+"\n";
			 $$->code += "not ax\nmov "+tempVar+", ax\n";
			 $$->setSymbol(tempVar);

			 delete $2;
		 }
		 | factor {
			 //fprintf(logout_er, "At line no: %d unary_expression : factor\n", line_count);
			 $$ = new SymbolInfo();
		  	 string str = $1->getName();
		  	 $$->setName(str);
			 $$->setType($1->getType());
		  	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 $$->code = $1->code;
			 $$->setSymbol($1->getSymbol());

			 delete $1;
		 }
		 ;

factor	: variable {
	//fprintf(logout_er, "At line no: %d factor : variable\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	$$->setType($1->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code = $1->code;
	$$->setSymbol($1->getSymbol());

	if($1->getCategory() == "notarray"){

	} else{
		string tempVar = newTempVar();
		tempVar_set.push_back(tempVar);
		variable_defined += tempVar + "\tdw\t'?'\n";
		variable_set.insert(tempVar + "\tdw\t'?'\n");
		// fprintf(codeout, "%s\tdw\t'?'\n",tempVar.c_str());
		$$->code +="mov ax, "+$1->getSymbol()+"[bx]\n";
		$$->code += "mov "+tempVar+", ax\n";
		$$->setSymbol(tempVar);

	}

	delete $1;
}
	| ID LPAREN {totalArguments = 0;} argument_list RPAREN {
		//fprintf(logout_er, "At line no: %d factor : ID LPAREN argument_list RPAREN\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName() + "(" + $4->getName() + ")";
		$$->setName(str);
		SymbolInfo* symbol = table->lookUp($1->getName());
		int t_args = 0;
		if(symbol){
			if(symbol->parameterList[symbol->parameterList.size() -1] == "function"){
				bool matched = true;
				for(int i = 0; i < $4->parameterList.size(); i++){
					if($4->parameterList[i] != symbol->parameterList[i+1]) matched = false;
				}
				if(matched == false) {
					fprintf(logout , "Error at line %d : function arguments types not matched\n\n", line_count);
					$$->setType("error");
					total_error++;
				} else {
					$$->setType(symbol->parameterList[0]);
					t_args = $4->parameterList.size();
				}
			}
			else{
				$$->setType("error");
				fprintf(logout, "Error at line %d : '%s' is not a function\n\n", line_count, $1->getName().c_str());
				total_error++;
			}
		} else{
			$$->setType("error");
			fprintf(logout, "Error at line %d : function '%s' not declared\n\n", line_count, $1->getName().c_str());
			total_error++;
		}

		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		$$->code += $4->code;
		string tempVar = newTempVar();
		tempVar_set.push_back(tempVar);
		variable_defined += tempVar + "\tdw\t'?'\n";
		variable_set.insert(tempVar + "\tdw\t'?'\n");

		if(current_function_name != "main" && current_function_name == $1->getName()){
			for(string var : tempVar_set){
				$$->code += "push "+var+"\n";
			}
		}
		// if(current_function_name != "main"){
		// 	for(int i = 1; i <= t_args; i++){
		// 		$$->code += "push f"+to_string(i)+"\n";
		// 	}
		// }
		$$->code += "call "+$1->getName()+"\n";

		if(current_function_name != "main" && current_function_name == $1->getName()){
			for(int i = tempVar_set.size()-1; i >=0; i--){
				string var = tempVar_set[i];
				$$->code += "pop "+var+"\n";
			}
		}

		for(int i = t_args; i >=1 ; i--){
			$$->code += "pop f"+to_string(i)+"\n";
		}
		
		$$->code += "mov "+tempVar+", ax\n";
		$$->setSymbol(tempVar);
		totalArguments = 0;

		delete $1;
		delete $4;
	}
	| LPAREN expression RPAREN {
		//fprintf(logout_er, "At line no: %d factor : LPAREN expression RPAREN\n", line_count);
		$$ = new SymbolInfo();
		string str = "(" + $2->getName() + ")";
		$$->setName(str);
		$$->setType($2->getType());
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		$$->code += $2->code;
		$$->setSymbol($2->getSymbol());

		delete $2;
	}
	| CONST_INT {
		//fprintf(logout_er, "At line no: %d factor : CONST_INT\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName();
		$$->setName(str);
		$$->setType("int");
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		string tempVar = newTempVar();
		tempVar_set.push_back(tempVar);
		variable_defined += tempVar + "\tdw\t'?'\n";
		variable_set.insert(tempVar + "\tdw\t'?'\n");
		$$->code += "mov ax, "+$1->getName()+"\n";
		$$->code += "mov " +tempVar+ ", ax\n";
		$$->setSymbol(tempVar);

		delete $1;
	}
	| CONST_FLOAT {
		//fprintf(logout_er, "At line no: %d factor : CONST_FLOAT\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName();
		$$->setName(str);
		$$->setType("float");
		//fprintf(logout_er, "\n%s\n\n", str.c_str());
		delete $1;
	}
	| variable INCOP {
		//fprintf(logout_er, "At line no: %d factor : variable INCOP\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName() + "++";
		$$->setName(str);
		$$->setType($1->getType());
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		$$->code = $1->code;
		$$->setSymbol($1->getSymbol());

		if($1->getCategory() == "notarray"){
			$$->code += "inc "+$1->getSymbol()+"\n";
		} else{
			$$->code +="inc "+$1->getSymbol()+"[bx]\n";
		}

		delete $1;
	}
	| variable DECOP {
		//fprintf(logout_er, "At line no: %d factor : variable DECOP\n", line_count);
		$$ = new SymbolInfo();
		string str = $1->getName() + "--";
		$$->setName(str);
		$$->setType($1->getType());
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		$$->code = $1->code;
		$$->setSymbol($1->getSymbol());

		if($1->getCategory() == "notarray"){
			$$->code += "dec "+$1->getSymbol()+"\n";
		} else{
			$$->code +="dec "+$1->getSymbol()+"[bx]\n";
		}

		delete $1;
	}
	;

argument_list : arguments {
	//fprintf(logout_er, "At line no: %d argument_list : arguments\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName();
	$$->setName(str);
	$$->parameterList.insert($$->parameterList.end(), $1->parameterList.begin(), $1->parameterList.end());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code = $1->code;
	$$->setSymbol($1->getSymbol());

	delete $1;
}
			  | {
				  //fprintf(logout_er, "At line no: %d argument_list : \n", line_count);
				  $$ = new SymbolInfo();
				  string str = "";
				  $$->setName(str);
				  //fprintf(logout_er, "\n%s\n\n", str.c_str());
			  }
			  ;

arguments : arguments COMMA logic_expression {
	//fprintf(logout_er, "At line no: %d arguments : arguments COMMA logic_expression\n", line_count);
	$$ = new SymbolInfo();
	string str = $1->getName() + ", " + $3->getName();
	$$->setName(str);
	$$->parameterList.insert($$->parameterList.end(), $1->parameterList.begin(), $1->parameterList.end());
	$$->parameterList.push_back($3->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	$$->code += $1->code + $3->code;
	$$->setSymbol($1->getSymbol());

	$$->code += "mov ax, "+$3->getSymbol()+"\n";
	string fVar = funct_call_var();
	$$->code += "push f"+to_string(totalArguments)+"\n";
	$$->code += "mov "+fVar+", ax\n";

	delete $1;
	delete $3;
}
	      | logic_expression {
			  //fprintf(logout_er, "At line no: %d arguments : logic_expression\n", line_count);
			  $$ = new SymbolInfo();
			  string str = $1->getName();
			  $$->setName(str);
			  $$->parameterList.push_back($1->getType());
			  //fprintf(logout_er, "\n%s\n\n", str.c_str());

			  $$->code += $1->code;
			  $$->setSymbol($1->getSymbol());

			  $$->code += "mov ax, "+$1->getSymbol()+"\n";
			  string fVar = funct_call_var();
			  $$->code += "push f"+to_string(totalArguments)+"\n";
			  $$->code += "mov "+ fVar+", ax\n";

			  delete $1;
		  }
	      ;


%%
int main(int argc,char *argv[])
{
	FILE* fp;

	if((fp=fopen(argv[1],"r"))==NULL) {
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	yyin=fp;
	yyparse();
	fprintf(logout, "Total lines: %d\n\n", line_count);
	fprintf(logout, "Total errors: %d\n", total_error);
	fclose(yyin);
	fclose(logout);
	fclose(codeout);
	fclose(fp);

	return 0;
}

bool matchFunction(vector<string> &a, vector<string> &b) {
	if(a.size() == b.size()) {
		for(int i = 0; i < a.size(); i++) {
			if(a[i] != b[i]) return false;
		}
	}
	else return false;
	return true;
}

string newLabel(){
	labelCount++;
	string ret = "Label" + to_string(labelCount);
	return ret;
}

string newTempVar(){
	tempCount++;
	string ret = "t" + to_string(tempCount);
	return ret;
}

string funct_call_var(){
	totalArguments++;
	string ret = "f" + to_string(totalArguments);
	return ret;
}

vector<string> split_token(const string& s, const string& delimeters){
	vector<string> tokens;
	char str[s.size()+1];
	char del[delimeters.size()+1];
	strcpy(str, s.c_str());
	strcpy(del, delimeters.c_str());

	for (auto i = strtok(str, del); i != NULL; i = strtok(NULL, del))
		tokens.push_back(i);
	return tokens;
}
