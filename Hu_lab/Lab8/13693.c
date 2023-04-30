#include<stdio.h>
#include<stdlib.h>
double f(){
    char c[20];
    scanf("%s",c);
    if(c[0]=='+'||c[0]=='-'||c[0]=='*'||c[0]=='/'){
        double a = f();
        double b = f(); 
        switch (c[0]){
            case '+':
            return a+b;
            case '-':
            return a-b;
            case '*':
            return a*b;
            case '/':
            return a/b;
        }
    }
    return atof(c);
}
int main(){
    double res = f();
    printf("%.4lf\n",res);
    return 0;
}