#include<stdio.h>
#include<string.h>
int main(){
    char name[10001]={" "};
    scanf("%s",name);
    int temper;
    scanf("%d",&temper);
    getchar();
    char c;
    short len=strlen(name);
    unsigned short correct=0;
    unsigned int incorrect=0;
    while(scanf("%c",&c)!=EOF){
        if(c=='/'){
            temper--;
            if(incorrect){
                incorrect--;
            }
            else if(correct){
                correct--;
            }
        }
        else if(c=='!'){
            if(temper)temper-=2;
            correct=0;
            incorrect=0;
        }
        else if(incorrect){
            printf("no\n");
            incorrect++;
        }
        else{
            if(c==name[correct]){
                printf("%hd\n",++correct);
                if(correct==len&&temper){
                    printf("DAISUKI!\n");
                    return 0;
                }
            }
            else{
                incorrect++;
                printf("no\n");
            }
        }
        if(temper<=0){break;}
    }
    printf("SAYONARA\n");
    return 0;
}