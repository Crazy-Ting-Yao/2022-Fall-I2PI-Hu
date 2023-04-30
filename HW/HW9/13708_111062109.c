#include<stdio.h>
#include<string.h>
int counter;
char s[41];
int len;
int check(int start,int end){
    for(int i=0;i<=(end-start)/2;i++){
        if(s[start+i]!=s[end-i]){
            return 0;
        }
    }
    return 1;
}
void recursion(int index){
    if(index==len){
        counter++;
        return;
    }
    for(int i=index;i<len;i++){
        if(check(index,i)){
            recursion(i+1);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        counter=0;
        scanf("%s",s);
        len = strlen(s);
        recursion(0);
        printf("%d\n",counter);
    }
    return 0;
}