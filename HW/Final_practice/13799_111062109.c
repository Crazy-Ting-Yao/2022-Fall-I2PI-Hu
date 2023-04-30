#include<stdio.h>
#include<stdlib.h>
int main(){
    int notperfect;
    int res=0;
    int n,k;
    scanf("%d %d",&n,&k);
    int* toomuch = (int*)calloc(sizeof(int),k+1);
    char* no = (char*)malloc(sizeof(char)*(k+1));
    char* onlyone = (char*)calloc(sizeof(char),(k+1));
    for(int i=0;i<=k;i++) no[i]=1;
    notperfect=k;
    int input[n];
    for(int i=0;i<n;i++) scanf("%d",&input[i]);
    for(int i=0;i<k-1;i++){
        if(no[input[i]]){
            no[input[i]]=0;
            notperfect--;
            //printf("%d ",notperfect);
            onlyone[input[i]]=1;
        }
        else if(onlyone[input[i]]){
            notperfect++;
            onlyone[input[i]]=0;
            toomuch[input[i]]=1;
        }
        else{
            toomuch[input[i]]++;
        }
    }
    //printf("%d ",notperfect);
    for(int i=k-1;i<n;i++){
        if(no[input[i]]){
            no[input[i]]=0;
            notperfect--;
            onlyone[input[i]]=1;
        }
        else if(onlyone[input[i]]){
            notperfect++;
            onlyone[input[i]]=0;
            toomuch[input[i]]=1;
        }
        else{
            toomuch[input[i]]++;
        }
        if(!notperfect) res++;
        if(toomuch[input[i-k+1]]>1) toomuch[input[i-k+1]]--;
        else if(toomuch[input[i-k+1]]==1){
            notperfect--;
            onlyone[input[i-k+1]]=1;
            toomuch[input[i-k+1]]=0;
        }
        else {
            notperfect++;
            onlyone[input[i-k+1]]=0;
            no[input[i-k+1]]=1;
        }
    }
    printf("%d\n",res);
    free(toomuch);
    free(no);
    free(onlyone);
    return 0;
}