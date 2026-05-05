#include <stdio.h>

double* calc_elements(double *ptr_array, int n) {
    for(int i=0; i<n; i++) {
        double orig = ptr_array[i];
        double new = ptr_array[i] += ptr_array[n-1];
        printf("| %2d | %5.2f | %6.2f |\n", i, orig, new);
        ptr_array[i] = new;
    }
}
