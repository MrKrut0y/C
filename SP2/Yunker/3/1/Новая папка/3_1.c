#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#include "functions1.c"

/*
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
        float new = ptr_array[i] += ptr_array[n-1];
        printf("| %2d | %5.2f | %6.2f |\n", i+1, orig, new);
        ptr_array[i] = new;
    }
}
*/

int main(void) {
    setlocale(LC_ALL, "Russian");

    int size;

    printf("¬ведите размер массива > ");
    scanf("%d", &size);
    double array[size];

    full_elements(array, size);
    put_elements(array, size);
    printf("\n");
    calc_elements(array, size);


    return 0;
}
