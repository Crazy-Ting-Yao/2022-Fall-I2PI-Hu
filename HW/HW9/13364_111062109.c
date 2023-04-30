#include<stdio.h>
#include<string.h>
int f(){
    char o[5001];
    scanf("%s",o);
    char d[5001];
    char osub[50][5001];
    scanf("%s",d);
    int index=1,num=0;
    int start=1;
    int r=0;
    while(o[++index]!='\0'){
        if(o[index]=='/'){
            r=0;
            for(int i=start;i<index;i++){
                osub[num][r++]=o[i];
            }
            osub[num++][r]='\0';
            start = ++index;
        }
    }
    r=0;
    for(int i=start;i<index;i++){
        osub[num][r++]=o[i];
    }
    osub[num++][r]='\0';
    index=1,start=1;
    char temp[5001];
    while(d[++index]!='\0'){
        if(d[index]=='/'){
            r=0;
            for(int i=start;i<index;i++){
                temp[r++]=d[i];
            }
            temp[r]='\0';
            int flag=0;
            for(int i=0;i<num;i++){
                if(!strcmp(osub[i],temp)){
                    osub[i][0]='\0';
                    flag=1;
                    break;
                }
            }
            if(!flag){
                return 0;
            }
            start = ++index;
        }
    }
    r=0;
    for(int i=start;i<index;i++){
        temp[r++]=d[i];
    }
    temp[r]='\0';
    int flag=0;
    for(int i=0;i<num;i++){
        if(!strcmp(osub[i],temp)){
            flag=1;
            break;
        }
    }
    if(!flag){
        return 0;
    }    
    return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        if(f()) printf("valid\n");
        else printf("not valid\n");
    }
    return 0;
}