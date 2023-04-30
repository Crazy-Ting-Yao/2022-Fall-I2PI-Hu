#include<stdio.h>
#include<stdlib.h>
int maze(int ** a,int * index,int loc,int m,int n,int *xpos,int *ypos){
    int x = xpos[loc];
    int y = ypos[loc];
    if(x!=0){
        if(a[x-1][y]==-1){
            return 1;
        }
        if(a[x-1][y]==1){
            a[x-1][y]=0;
            xpos[(*index)] = x-1;
            ypos[(*index)] = y;
            (*index)++;
        }
    }
    if(x!=(m-1)){
        if(a[x+1][y]==-1){
            return 1;
        }
        if(a[x+1][y]==1){
            a[x+1][y]=0;
            xpos[(*index)] = x+1;
            ypos[(*index)] = y;
            (*index)++;
        }
    }
    if(y!=0){
        if(a[x][y-1]==-1){
            return 1;
        }
        if(a[x][y-1]==1){
            a[x][y-1]=0;
            xpos[(*index)] = x;
            ypos[(*index)] = y-1;
            (*index)++;
        }
    }
    if(y!=(n-1)){
        if(a[x][y+1]==-1){
            return 1;
        }
        if(a[x][y+1]==1){
            a[x][y+1]=0;
            xpos[(*index)] = x;
            ypos[(*index)] = y+1;
            (*index)++;
        }
    }
    return 0;    
}
int main(){
    int m, n;
    scanf("%d %d",&m,&n);
    int** map = (int**)calloc(sizeof(int*),m);
    for(int i=0;i<m;i++){
        map[i] = (int*)calloc(sizeof(int),n);
    }
    int T;
    scanf("%d",&T);
    while(T--){
        int* xpos = (int*)calloc(sizeof(int),m*n);
        int* ypos = (int*)calloc(sizeof(int),m*n);
        char tem;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf(" %c", &tem);
                if(tem=='.'){
                    map[i][j] = 1;
                }
                else if(tem=='S'){
                    map[i][j] = 0;
                    xpos[0] = i;
                    ypos[0] = j;
                }
                else if(tem=='D'){
                    map[i][j] = -1;
                }
                else{
                    map[i][j] = 0;
                }
            }
        }
        int index=1,flag=1;
        for(int i=0;i<index;i++){
            if(maze(map,&index,i,m,n,xpos,ypos)){
                printf("ESCAPE!\n");
                flag=0;
                break;
            }
        }
        if(flag){
            printf("QQ\n");
        }
        free(xpos);
        free(ypos);
    }
    for(int i=0;i<m;i++){
        free(map[i]);
    }
    free(map);
    return 0;
}