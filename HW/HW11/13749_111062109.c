#include <stdlib.h>
#include <string.h>
char **split_(char* str, char* pattern, int* split_num){
    (*split_num)=0;
    char** res = (char**) malloc(sizeof(char*)*500);
    int slen = strlen(str);
    int plen = strlen(pattern);
    int start=0;
    for(int i=0;i<=(slen-plen);i++){
        int flag=1;
        for(int j=0;j<plen;j++){
            if(str[j+i]!=pattern[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            if(start==i){
                i+=plen-1;
                start=i+1;
                continue;
            }
            int tmplen=i-start;
            res[(*split_num)] = (char*) malloc(sizeof(char)*(tmplen+1));
            for(int k=0;k<tmplen;k++){
                res[(*split_num)][k]=str[k+start];
            }
            res[(*split_num)][tmplen]='\0';
            i+=plen-1;
            start=i+1;
            (*split_num)++;
        }
    }
    if(start!=slen){
        int tmplen=slen-start;
        res[(*split_num)] = (char*) malloc(sizeof(char)*(tmplen+1));
        for(int k=0;k<tmplen;k++){
            res[(*split_num)][k]=str[k+start];
        }
        res[(*split_num)][tmplen]='\0'; 
        (*split_num)++;       
    }
    return res;
}
void free_(char **result, int split_num){
    for(int i=0;i<split_num;i++){
        free(result[i]);
    }
}