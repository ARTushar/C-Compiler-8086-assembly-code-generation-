int foo2(int p, int q){
    return p+q;
}

int foo(int a, int b){
    int r,s,t;
    r = 5;
    s = 7;
    t = foo2(r, s);
    t = t + a + b;

    return t;
}
int max(int a, int b){
    if(a >b) return a;
    return b;
}
int max_three(int a,int b, int c){
   return max(a,max(b,c));
 
}

int fib(int n){
    if(n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}

int fact(int n){
    if(n <= 1){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int p, q, r[6];
    p = 5;
    q = 4;
    p = fact(5);
    println(p);
    int sum ;
    sum = 0;
    q = 1;
    while(q <= 10){
        sum = sum + q;
        q++;
    }
    println(sum);

    return 0;
}