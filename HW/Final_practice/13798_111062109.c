#include<stdio.h>
#include<stdlib.h>
#include<string.h>
short** DP;
char s1[3100];
char s2[3100];
int s1_len,s2_len;
#define max(A,B) (A>B?A:B)
int recursion(int start1,int start2){
    if(start1==s1_len||start2==s2_len) return 0;
    if(DP[start1][start2]!=-1) return DP[start1][start2];
    if(s1[start1]==s2[start2]){
        DP[start1][start2] = recursion(start1+1,start2+1)+1;
        return DP[start1][start2];
    }
    DP[start1][start2] = max(recursion(start1+1,start2),recursion(start1,start2+1));
    return DP[start1][start2];
}
int main(){
    scanf("%s",s1);
    scanf("%s",s2);
    s1_len=strlen(s1);
    s2_len=strlen(s2);
    DP = (short**)malloc(sizeof(short*)*s1_len);
    for(int i=0;i<s1_len;i++){
        DP[i] = (short*)malloc(sizeof(short)*s2_len);
        for(int j=0;j<s2_len;j++){
            DP[i][j]=-1;
        }
    }
    int res = recursion(0,0);
    printf("%d\n",res);
    for(int j=0;j<s1_len;j++){
        free(DP[j]);
    }
    free(DP);
    return 0;
}
