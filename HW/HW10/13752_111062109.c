#include<stdio.h>
#include<string.h>
char DP[21][1000000];
void reverse(int i){
    char c[1000000];
    strcpy(c,DP[i]);
    int len=strlen(c);
    for(int j=0;j<len;j++){
        DP[i][j]=c[len-j-1];
    }
}
void invert(int i){
    int len=strlen(DP[i]);
    for(int j=0;j<len;j++){
        DP[i][j]=((DP[i][j]=='1')?'0':'1');
    }
}
void recursion(int i){
    int len=strlen(DP[i-1]);
    strcat(DP[i],DP[i-1]);
    invert(i-1);
    reverse(i-1);
    DP[i][len]='1';
    strcat(DP[i],DP[i-1]);
}
int main(){
    DP[0][0]='0';
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++){
        recursion(i);
    }
    while(t--){
        int x;
        scanf("%d",&x);
        printf("%c\n",DP[n][x]);
    }
    return 0;
}