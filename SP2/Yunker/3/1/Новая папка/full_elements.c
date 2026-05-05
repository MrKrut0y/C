#include <stdio.h>

double* full_elements(double *ptr_array, int n) {
    srand(time(NULL));

    for (int i=0;i<n;i++) {
        ptr_array[i] = (double)(rand() % 1000) / 10.0;
    }

    return ptr_array;
}
