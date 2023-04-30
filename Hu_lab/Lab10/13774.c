#include<stdio.h>
#include<string.h>
char strings[3][4000000];
char temp1[4000000];
char temp2[4000000];
void recursion(int ind){
    int a = ind%3;
    int b = (ind-1)%3;
    int c = (ind-2)%3;
    strcpy(strings[a],strings[b]);
    int len = strlen(strings[a]);
    strings[a][len++]='1';
    strings[a][len]='\0';
    len = strlen(strings[b]);
    for(int i=0;i<len;i++){
        temp1[i] = (strings[b][i]=='1')?'0':'1';
    }
    for(int i=0;i<len;i++){
        temp2[i] = temp1[len-i-1];
    }
    temp2[len] = '\0';
    strcat(strings[a],temp2);
    len = strlen(strings[a]);
    strings[a][len++]='0';
    strings[a][len]='\0';
    len = strlen(strings[c]);
    strcpy(temp1,strings[c]);
    for(int i=0;i<len;i++){
        temp2[i] = temp1[len-i-1];
    }
    for(int i=0;i<len;i++){
        temp2[i] = (temp2[i]=='1')?'0':'1';
    }
    temp2[len]='\0';
    strcat(strings[a],temp2);
    return;
}
int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    strings[0][0]='0';
    strings[1][0]='1';
    for(int i=2;i<=n;i++){
        recursion(i);
    }
    while(t--){
        int k;
        scanf("%d",&k);
        printf("%c\n",strings[(n%3)][k]);
    }
    return 0;
}