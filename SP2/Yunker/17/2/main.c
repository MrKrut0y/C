#include <stdio.h>
#include <locale.h>
#include "list.h"
#include <time.h>
#include <stdlib.h>

int main() {

    setlocale(LC_ALL, "Russian");

    srand(time(NULL));
    
    printf("rand10_(10) %d\n", rand10_(10));

    printf("rand_double(-5, 5) %.2f\n", rand_double(-5, 5));
    
    printf("rand10(10, 10)\n");
    int* int_arr = rand10(10, 10);
    if (int_arr != NULL) {
        print_int_arr(int_arr, 10);
        free(int_arr);
    }
    printf("\n");
    
    printf("rand_double_(10, 5)\n");
    double* double_arr = rand_double_(10, 5);
    if (double_arr != NULL) {
        print_double_arr(double_arr, 10);
        free(double_arr);
    }
    printf("\n");
    
    printf("rand int(1, 10) \n");
    for (int i=0; i<10; i++) {
        printf("%d ", rand10_(10));
    }
    printf("\n");
    printf("\n");
    
    printf("rand double(-5, 5): \n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", rand_double(-5, 5));
    }
    printf("\n");
    
    int* arr1 = rand10(8, 10);
    int* arr2 = rand10(8, 10);

    printf("\n");

    printf("comparison\n");
    
    printf("1. ");
    print_int_arr(arr1, 8);
    
    printf("2. ");
    print_int_arr(arr2, 8);
    
    free(arr1);
    free(arr2);
    
    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}