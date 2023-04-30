#include<stdio.h>
short sudoku[9][9];
int check(int m,int n,int val){
    for(int i=0;i<9;i++){
        if(sudoku[i][n]==val){
            return 0;
        }
        if(sudoku[m][i]==val){
            return 0;
        }
    }
    int cubex=m/3*3;
    int cubey=n/3*3;
    for(int i=cubex;i<cubex+3;i++){
        for(int j=cubey;j<cubey+3;j++){
            if(sudoku[i][j]==val){
                return 0;
            }
        }
    }    
    return 1;
}
int solve(int m,int n){
    int flag=0;
    int k = 9 * m + n + 1;
    if(k==82){
        return 1;
    }
    if(sudoku[m][n]!=0){
        flag = solve(k/9,k%9);
        if(flag)return 1;
        else return 0;
    }
    for(int i=1;i<10;i++){
        if(check(m,n,i)){
            sudoku[m][n]=i;
            flag = solve(k/9,k%9);
            if(flag){
                return 1;
            }
            sudoku[m][n]=0;
        }
    }
    return 0;
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%hd",&sudoku[i][j]);
        }
    }
    if(solve(0,0)){
        for(int i=0;i<9;i++){
            for(int j=0;j<8;j++){
                printf("%hd ",sudoku[i][j]);
            }
            printf("%hd\n",sudoku[i][8]);
        }
    }
    else{
        printf("no solution\n");
    }
    return 0;
}