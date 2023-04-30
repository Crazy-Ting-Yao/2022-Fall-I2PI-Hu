#include<stdio.h>
int main(){
    char c[6];
    scanf("%s",&c);
    for(int i=0;i<5;i++){
        c[i] -= 32;
        c[i] = 'A'+'Z'-c[i];
    }
    printf("%s\n",c);
    return 0;
}