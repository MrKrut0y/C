#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

#define K 10
#define N 100
#define H 10

int rand10_(int mmax) {

    return 1 + rand() % mmax ;
}

int* rand10(int n, int mmax) {

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }

    for (int i=0; i<n; i++) {
        arr[i] = 1 + rand() % mmax;
    }
    
    return arr;
}

double* rand_double_(int n, double dm) {

    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        return NULL;
    }

    for (int i=0; i<n; i++) {
        arr[i] = (double)rand() / RAND_MAX * (2.0 * dm) - dm;
    }
    
    return arr;
}

double rand_double(double dmin, double dmax) {

    return dmin+1.f*(dmax-dmin)*rand() / RAND_MAX;
}

void print_int_arr(int* arr, int n) {

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_double_arr(double* arr, int n) {

    for (int i=0; i<n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void build_histogram(int* counter, int height, int k) {

    int max_counter = 0;
    for (int i=0; i<k; i++) {
        if (counter[i] > max_counter) {
            max_counter = counter[i];
        }
    }
    
    for (int row = height; row > 0; row--) {
        printf("  ");
        for (int i=0; i<k; i++) {
            int column_height = (int)((double)counter[i] / max_counter * height);
            if (column_height >= row) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n  ");
    
    for (int i = 0; i < k; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n\n");
    
    for (int i = 0; i < k; i++) {
        printf("%d: %d  ", i + 1, counter[i]);
    }
    printf("\n");
}