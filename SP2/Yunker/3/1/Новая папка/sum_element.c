#include <stdio.h>

double sum_element(double *ptr_array, int begin, int end) {
    double sum = 0.0;

    for (int i = begin;i<=end;i++) {
        sum += ptr_array[i];
    }
    return sum;
}
