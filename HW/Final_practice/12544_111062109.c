#include<stdio.h>
#include<string.h>
char title[8] =  "<title>";
char a[5] =  "</a>";
int res=0;
int t=0;
int main(){
    char s[1001];
    while(fgets(s,1001,stdin)!=NULL){
        int len = strlen(s);
        if(!t){
            for(int i=0;i<len-15;i++){
                int flag=0;
                for(int j=0;j<7;j++){
                    if(title[j]!=s[i+j]){
                        flag=1;
                        break;
                    }
                }
                if(flag) continue;
                t=1;
                for(int j=i+7;s[j]!='<';j++){
                    printf("%c",s[j]);
                }
                printf("\n");
                break;
            }
        }
        for(int i=0;i<len-4;i++){
            int flag=0;
            for(int j=0;j<4;j++){
                if(a[j]!=s[i+j]){
                    flag=1;
                    break;
                }
            }
            if(flag) continue;
            res++;
        }
    }
    printf("%d\n",res);
    return 0;
}