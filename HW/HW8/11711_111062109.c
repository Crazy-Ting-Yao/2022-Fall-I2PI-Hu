#include <stdlib.h>
unsigned*** new_3d_array(unsigned n, unsigned m, unsigned k) {
    unsigned*** arrr = malloc(sizeof(unsigned**)*n);
    unsigned**arr = malloc(sizeof(unsigned**)*n*m);
    unsigned*ar = malloc(sizeof(unsigned)*m*n*k);
    for(int i=0;i<n;i++){
        arrr[i] = arr+i*m;
        for(int j=0;j<m;j++){
            arrr[i][j] = ar+i*m*k+j*k;
        }
    }
    return arrr;
}
void delete_3d_array(unsigned*** arr) {
    free(**arr);
    free(*arr);
    free(arr);
}
