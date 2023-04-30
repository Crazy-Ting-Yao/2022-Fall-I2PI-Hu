#include<stdio.h>
void transfer(){
    char s[100];
    scanf("%s",s);
    switch(s[0]){
        case '+': case '-': case '*': case '/':
        transfer();
        printf(" ");
        transfer();
        printf(" ");
        printf("%c",s[0]);
        break;
        default:
        printf("%s",s);
    }
    return;
}
int main(){
    transfer();
    return 0;
}