//13660
#include<stdio.h>
int main(){
    char c;
    scanf("%c",&c);
    int a = c-'A';
    for(int i=0;i<a;i++){
        for(int j=a;j>i;j--){
            printf(" ");
        }
        for(int j=0;j<i;j++){
            char r = j+'A';
            printf("%c",r);
        }
        for(int j=i;j>=0;j--){
            char r = j+'A';
            printf("%c",r);
        }
        printf("\n");
    }
    for(int i=a;i>=0;i--){
        for(int j=a;j>i;j--){
            printf(" ");
        }
        for(int j=0;j<i;j++){
            char r = j+'A';
            printf("%c",r);
        }
        for(int j=i;j>=0;j--){
            char r = j+'A';
            printf("%c",r);
        }
        printf("\n");
    }
}