#include <stdio.h>

int find_element(double *ptr_array, int n, double element) {
    for (int i=0;i<n;i++) {
        if (ptr_array[i] == element) {
            return i;
        }
    }
    return -1;
}
