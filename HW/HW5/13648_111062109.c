//13648
#include<stdio.h>
int main(){
    char c[101][101];
    int n,s;
    scanf("%d",&n);
    scanf("%d",&s);
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            getchar();
            c[i][j]=getchar();
        }
        getchar();
    }
    int mode=0;
    for(int i=0;i<s;i++){
        if(mode){
            char max='A';
            int indexi=0,indexj=0;
            if(x!=0){
                if(y!=0){
                    if(c[x-1][y-1]>=max){
                        max=c[x-1][y-1];
                        indexi=x-1;
                        indexj=y-1;
                    }
                }
                if(c[x-1][y]>=max){
                    max=c[x-1][y];
                    indexi=x-1;
                    indexj=y;
                }
                if(y!=n-1){
                    if(c[x-1][y+1]>=max){
                        max=c[x-1][y+1];
                        indexi=x-1;
                        indexj=y+1;
                    }
                }
            }
            if(y!=0){
                if(c[x][y-1]>=max){
                    max=c[x][y-1];
                    indexi=x;
                    indexj=y-1;
                }        
            }
            if(y!=n-1){
                if(c[x][y+1]>=max){
                    max=c[x][y+1];
                    indexi=x;
                    indexj=y+1;
                }        
            }
            if(x!=n-1){
                if(y!=0){
                    if(c[x+1][y-1]>=max){
                        max=c[x+1][y-1];
                        indexi=x+1;
                        indexj=y-1;
                    }
                }
                if(c[x+1][y]>=max){
                    max=c[x+1][y];
                    indexi=x+1;
                    indexj=y;
                }
                if(y!=n-1){
                    if(c[x+1][y+1]>=max){
                        max=c[x+1][y+1];
                        indexi=x+1;
                        indexj=y+1;
                    }
                }
            }
            printf("%c",c[x][y]);
            switch (max){
            case 'a': case 'f': case 'k': case 'p': case 'E': case 'J': case 'O': case 'T':
                if(y==0)return 0;
                y--;
                break;
            case 'b': case 'g': case 'l': case 'q': case 'D': case 'I': case 'N': case 'S':
                if(y==n-1)return 0;
                y++;                
                break;
            case 'c': case 'h': case 'm': case 'r': case 'C': case 'H': case 'M': case 'R':
                if(x==0)return 0;
                x--;                
                break;
            case 'd': case 'i': case 'n': case 's': case 'B': case 'G': case 'L': case 'Q':
                if(x==n-1)return 0;
                x++;                
                break;
            case 'e': case 'j': case 'o': case 't': case 'A': case 'F': case 'K': case 'P':
                mode=0;
            default:
                x = indexi;
                y = indexj;
                break;
            }   
        }
        else{
            char min='z';
            int indexi=0,indexj=0;
            if(x!=0){
                if(y!=0){
                    if(c[x-1][y-1]<=min){
                        min=c[x-1][y-1];
                        indexi=x-1;
                        indexj=y-1;
                    }
                }
                if(c[x-1][y]<=min){
                    min=c[x-1][y];
                    indexi=x-1;
                    indexj=y;
                }
                if(y!=n-1){
                    if(c[x-1][y+1]<=min){
                        min=c[x-1][y+1];
                        indexi=x-1;
                        indexj=y+1;
                    }
                }
            }
            if(y!=0){
                if(c[x][y-1]<=min){
                    min=c[x][y-1];
                    indexi=x;
                    indexj=y-1;
                }        
            }
            if(y!=n-1){
                if(c[x][y+1]<=min){
                    min=c[x][y+1];
                    indexi=x;
                    indexj=y+1;
                }        
            }
            if(x!=n-1){
                if(y!=0){
                    if(c[x+1][y-1]<=min){
                        min=c[x+1][y-1];
                        indexi=x+1;
                        indexj=y-1;
                    }
                }
                if(c[x+1][y]<=min){
                    min=c[x+1][y];
                    indexi=x+1;
                    indexj=y;
                }
                if(y!=n-1){
                    if(c[x+1][y+1]<=min){
                        min=c[x+1][y+1];
                        indexi=x+1;
                        indexj=y+1;
                    }
                }
            }
            printf("%c",c[x][y]);
            switch (min){
            case 'a': case 'f': case 'k': case 'p': case 'E': case 'J': case 'O': case 'T':
                if(y==0)return 0;
                y--;
                break;
            case 'b': case 'g': case 'l': case 'q': case 'D': case 'I': case 'N': case 'S':
                if(y==n-1)return 0;
                y++;                
                break;
            case 'c': case 'h': case 'm': case 'r': case 'C': case 'H': case 'M': case 'R':
                if(x==0)return 0;
                x--;                
                break;
            case 'd': case 'i': case 'n': case 's': case 'B': case 'G': case 'L': case 'Q':
                if(x==n-1)return 0;
                x++;                
                break;
            case 'e': case 'j': case 'o': case 't': case 'A': case 'F': case 'K': case 'P':
                mode=1;
            default:
                x = indexi;
                y = indexj;
                break;
            }          
        }
    }
    printf("%c",c[x][y]);
    return 0;
}