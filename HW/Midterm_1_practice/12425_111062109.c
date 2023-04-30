#include<stdio.h>
#include<string.h>
int main(){
    char c[1001];
    while(scanf("%s",c)!=EOF){
        char res[4001];
        int counter=1;
        float rate;
        int len = strlen(c);
        char temp=c[0];
        int index=0;
        for(int i=1;i<len;i++){
            if(temp==c[i]){
                counter++;
            }
            else{
                if(counter<10){
                    res[index++]=counter+'0';
                }
                else if(counter<100){
                    res[index++]=counter/10+'0';
                    res[index++]=counter%10+'0';
                }
                else{
                    res[index++]=counter/100+'0';
                    res[index++]=(counter/10)%10+'0';
                    res[index++]=counter%10+'0';
                }
                if(temp>='0'&&temp<='9'){
                    res[index++]='\'';
                    res[index++]=temp;
                    res[index++]='\'';
                }
                else{
                    res[index++]=temp;
                }
                temp=c[i];
                counter=1;
            }
            if(i==len-1){
                if(counter<10){
                    res[index++]=counter+'0';
                }
                else if(counter<100){
                    res[index++]=counter/10+'0';
                    res[index++]=counter%10+'0';
                }
                else{
                    res[index++]=counter/100+'0';
                    res[index++]=(counter/10)%10+'0';
                    res[index++]=counter%10+'0';
                }
                if(temp>='0'&&temp<='9'){
                    res[index++]='\'';
                    res[index++]=temp;
                    res[index++]='\'';
                }
                else{
                    res[index++]=temp;
                }
                res[index]='\0';         
            }
        }
        printf("%s\n",res);
        int reslen = strlen(res);
        rate = (float)reslen/len;
        if(rate>=1){
            printf("the string can't zip\n");
        }
        else{
            printf("compress rate:%6.3f\n",rate); 
        }
    }
}