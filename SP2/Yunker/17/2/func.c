#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>


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