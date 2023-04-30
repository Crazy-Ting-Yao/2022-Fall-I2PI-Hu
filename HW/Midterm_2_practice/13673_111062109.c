#include<stdio.h>
#include<math.h>
int error=0;
int recursion(int n){
    if(n==-1){
        error = 1;
        return 0;
    }
    char c;
    int x=0;
    if((c = getchar()) ==EOF){
        error = 1;
        return 0;
    }
    switch (c){
    case '0':
        return 0;
    case '1':
        return (pow(2,n)*pow(2,n));
    case '2':
        for(int i=0;i<4;i++){
            x += recursion(n-1);
        }
        return x;
    default:
        error=1;
        return 0;
    }
}
int main(){
    int k;
    scanf("%d",&k);
    getchar();
    int res = recursion(k);
    char test;
    if((test=getchar())!=EOF&&test!='\n'){
        error=1;
    }
    if(error){
        printf("Domo");
        return 0;
    }
    printf("%d",res);
    return 0;
}