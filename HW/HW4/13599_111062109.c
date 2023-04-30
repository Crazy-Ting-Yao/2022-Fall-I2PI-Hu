#include<stdio.h>
int main(){
    short piclen,reflen;
    scanf("%hd",&piclen);
    short pic[20][20];
    for(short i=0;i<piclen;i++){
        for(short j=0;j<piclen;j++){
            scanf("%hd",&pic[i][j]);
        }
    }
    scanf("%hd",&reflen);
    short ref[20][20];
    for(short i=0;i<reflen;i++){
        for(short j=0;j<reflen;j++){
            scanf("%hd",&ref[i][j]);
        }
    }
    int counter=0;
    for(short i=0;i<=piclen-reflen;i++){
        for(short j=0;j<=piclen-reflen;j++){
            short flag=1;
            for(short k=0;k<reflen;k++){
                for(short l=0;l<reflen;l++){
                    if(ref[k][l]!=pic[k+i][l+j]&&ref[k][l]==1){
                        flag=0;break;
                    }
                }
                if(flag==0){break;}
            }
            if(flag){counter++;}
        }
    }
    printf("%d\n",counter);
    return 0;
}