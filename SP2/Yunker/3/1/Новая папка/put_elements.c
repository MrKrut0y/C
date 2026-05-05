#include <stdio.h>

int put_elements(double *ptr_array, int n) {
    for (int i=0;i<n;i++) {
        printf("%.2f\n", ptr_array[i]);
    }
}
