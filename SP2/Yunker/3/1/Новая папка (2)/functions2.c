#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


double* full_elements(double *ptr_array, int n) {
    srand(time(NULL));

    for (int i=0;i<n;i++) {
        ptr_array[i] = (double)(rand() % 1000) / 10.0;
    }

    return ptr_array;
}

int put_elements(double *ptr_array, int n) {
    for (int i=0;i<n;i++) {
        printf("%.2f\n", ptr_array[i]);
    }
}

double* calc_elements(double *ptr_array, int n) {
    for(int i=0; i<n; i++) {
        double orig = ptr_array[i];
        double new = ptr_array[i] += ptr_array[n-1];
        printf("| %2d | %5.2f | %6.2f |\n", i, orig, new);
        ptr_array[i] = new;
    }
}

double sum_element(double *ptr_array, int begin, int end) {
    double sum = 0.0;

    for (int i = begin;i<=end;i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double *ptr_array, int n, double element) {
    for (int i=0;i<n;i++) {
        if (ptr_array[i] == element) {
            return i;
        }
    }
    return -1;
}
