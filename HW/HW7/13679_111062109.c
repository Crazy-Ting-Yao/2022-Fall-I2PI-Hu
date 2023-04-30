#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
long long int result = LLONG_MIN;
int size

int check(int x, int y, int **occupied) {
    for (int i = x - 1; i >= 0; i--) {
        if (occupied[i][y]) {
            return 0;
        }
        if ((y - (x - i)) >= 0) {
            if (occupied[i][y - (x - i)]) {
                return 0;
            }
        }
        if ((y + (x - i)) < size) {
            if (occupied[i][y + (x - i)]) {
                return 0;
            }
        }
    }
    return 1;
}
int pvz(int n, long long int account, long long int **garden, int **occupied) {
    if (n == size) {
        if (account > result) {
            result = account;
        }
        return 1;
    }
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (check(n, i, occupied)) {
            occupied[n][i] = 1;
            flag += pvz(n + 1, (account + garden[n][i]), garden, occupied);
            occupied[n][i] = 0;
        }
    }
    return flag;
}
int main() {
    scanf("%d", &size);
    long long int **garden =
        (long long int **)calloc(sizeof(long long int *), size);
    int **occupied = (int **)calloc(sizeof(int *), size);
    for (int i = 0; i < size; ++i) {
        garden[i] = (long long int *)calloc(sizeof(long long int), size);
        occupied[i] = (int *)calloc(sizeof(int), size);
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%lld", &garden[i][j]);
            occupied[i][j] = 0;
        }
    }
    int x = pvz(0, 0, garden, occupied);
    if (x > 0) {
        printf("%lld\n", result);
    } else {
        printf("no solution\n");
    }
    for (int i = 0; i < size; i++) {
        free(garden[i]);
        free(occupied[i]);
    }
    free(garden);
    free(occupied);
    return 0;
}