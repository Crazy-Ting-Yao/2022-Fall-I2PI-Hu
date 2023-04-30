#include<stdio.h>
#include<stdlib.h>
#include<string.h>
short** tables;
void clear(){
    for(int i=0;i<10;i++){
        memset(tables[i],0,sizeof(short)*10001);
    }   
}
void print(){
    for(int i=0;i<10;i++){
        printf("%d:",i);
        int flag=0;
        for(int j=0;tables[i][j];j++){
            flag=1;
            printf(" %d",tables[i][j]);
        }
        if(!flag) printf(" No card");
        puts("");
    }
}
void all(int num,int len){
    clear();
    for(int i=0;i<10;i++){
        for(int j=0;j<len;j++) tables[i][j] = num; 
    }
}
void place(int t,int len,short* seq){
    memset(tables[t],0,sizeof(short)*10001);
    for(int i=0;i<len;i++) tables[t][i]=seq[i];
}
void swap(int t1,int t2){
    short* temp = tables[t1];
    tables[t1] = tables[t2];
    tables[t2] = temp;
}

void shiftleft(){
    short* temp = tables[0];
    for(int i=0;i<9;i++) tables[i] = tables[i+1];
    tables[9] = temp;
}
void shiftright(){
    short* temp = tables[9];
    for(int i=9;i>0;i--){
        tables[i] = tables[i-1];
    }
    tables[0] = temp;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char s[11];
    tables = (short**)malloc(sizeof(short*)*10);
    for(int i=0;i<10;i++) tables[i] = (short*)calloc(sizeof(short),10001);
    while(1){
        scanf("%s",s);
        if(!strcmp(s,"print")) print();
        else if(!strcmp(s,"all")){
            int a,b;
            scanf("%d %d",&a,&b);
            all(a,b);
        }
        else if(!strcmp(s,"place")){
            int t,len;
            scanf("%d %d",&t,&len);
            short* seq = (short*)malloc(sizeof(short)*len);
            for(int i=0;i<len;i++) scanf("%hd",&seq[i]);
            place(t,len,seq);
            free(seq);
        }
        else if(!strcmp(s,"swap")){
            int t1,t2;
            scanf("%d %d",&t1,&t2);
            swap(t1,t2);
        }
        else if(!strcmp(s,"clear")) clear();
        else if(!strcmp(s,"shiftleft")) shiftleft();
        else if(!strcmp(s,"shiftright")) shiftright();
        else if(!strcmp(s,"exit")) break;
    }
    for(int i=0;i<10;i++) free(tables[i]);
    free(tables);
    return 0;
}