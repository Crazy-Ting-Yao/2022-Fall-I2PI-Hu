#include<stdio.h>
#include<stdlib.h>
typedef struct Step{
    int xpos;
    int ypos;
    int num;
}Steps;
int panda(int ** a,int * index,int loc,int m,int n,Steps *step){
    if((step[loc].xpos)!=0){
        if(a[(step[loc].xpos)-1][step[loc].ypos]==-1){
            return step[loc].num+1;
        }
        else if(a[(step[loc].xpos)-1][step[loc].ypos]==1){
            a[(step[loc].xpos)-1][step[loc].ypos]=0;
            step[*index].xpos = (step[loc].xpos)-1;
            step[*index].ypos = step[loc].ypos;
            step[*index].num = (step[loc].num)+1;
            (*index)++;
        }
    }
    if((step[loc].xpos)!=m-1){
        if(a[(step[loc].xpos)+1][step[loc].ypos]==-1){
            return (step[loc].num)+1;
        }
        else if(a[(step[loc].xpos)+1][step[loc].ypos]==1){
            a[(step[loc].xpos)+1][step[loc].ypos]=0;
            step[*index].xpos = (step[loc].xpos)+1;
            step[*index].ypos = step[loc].ypos;
            step[*index].num = (step[loc].num)+1;
            (*index)++;
        }
    }
    if((step[loc].ypos)!=0){
        if(a[step[loc].xpos][(step[loc].ypos)-1]==-1){
            return (step[loc].num)+1;
        }
        else if(a[step[loc].xpos][step[loc].ypos-1]==1){
            a[step[loc].xpos][(step[loc].ypos)-1]=0;
            step[*index].xpos = step[loc].xpos;
            step[*index].ypos = (step[loc].ypos)-1;
            step[*index].num = (step[loc].num)+1;
            (*index)++;
        }
    }
    if(step[loc].ypos!=n-1){
        if(a[step[loc].xpos][(step[loc].ypos)+1]==-1){
            return step[loc].num+1;
        }
        else if(a[step[loc].xpos][(step[loc].ypos)+1]==1){
            a[step[loc].xpos][(step[loc].ypos)+1]=0;
            step[*index].xpos = step[loc].xpos;
            step[*index].ypos = (step[loc].ypos)+1;
            step[*index].num = (step[loc].num)+1;
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
    Steps* steps = (Steps*)calloc(sizeof(Steps),m*n);
    char tem;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf(" %c ", &tem);
            if(tem=='.'){
                map[i][j] = 1;
            }
            else if(tem=='S'){
                map[i][j] = 0;
                steps[0].xpos = i;
                steps[0].ypos = j;
                steps[0].num = 0;
            }
            else if(tem=='M'){
                map[i][j] = -1;
            }
            else{
                map[i][j] = 0;
            }
        }
    }
    int index=1,res;
    for(long i=0;i<index;i++){
        res = panda(map,&index,i,m,n,steps);
        if(res){
            printf("%d\n",res);
            break;
        }
    }
    for(int i=0;i<m;i++){
        free(map[i]);
    }
    free(map);
    free(steps);
    return 0;
}