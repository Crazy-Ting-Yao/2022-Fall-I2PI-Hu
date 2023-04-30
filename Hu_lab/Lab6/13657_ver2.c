#include<stdio.h>
#include<stdlib.h>
int main(){
    int m, n;
    scanf("%d %d",&m,&n);
    char map[m][n];
    int T;
    scanf("%d",&T);
    while(T--){
        int xpos[m*n];
        int ypos[m*n];
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
            int x = xpos[i];
            int y = ypos[i];
            if(x!=0){
                if(map[x-1][y]==-1){
                    flag=0;
                    printf("ESCAPE!\n");
                    break;
                }
                if(map[x-1][y]==1){
                    map[x-1][y]=0;
                    xpos[index] = x-1;
                    ypos[index] = y;
                    index++;
                }
            }
            if(x!=(m-1)){
                if(map[x+1][y]==-1){
                    flag=0;
                    printf("ESCAPE!\n");
                    break;
                }
                if(map[x+1][y]==1){
                    map[x+1][y]=0;
                    xpos[index] = x+1;
                    ypos[index] = y;
                    index++;
                }
            }
            if(y!=0){
                if(map[x][y-1]==-1){
                    flag=0;
                    printf("ESCAPE!\n");
                    break;
                }
                if(map[x][y-1]==1){
                    map[x][y-1]=0;
                    xpos[index] = x;
                    ypos[index] = y-1;
                    index++;
                }
            }
            if(y!=(n-1)){
                if(map[x][y+1]==-1){
                    flag=0;
                    printf("ESCAPE!\n");
                    break;
                }
                if(map[x][y+1]==1){
                    map[x][y+1]=0;
                    xpos[index] = x;
                    ypos[index] = y+1;
                    index++;
                }
            }
        }
        if(flag){
            printf("QQ\n");
        }
    }
    return 0;
}