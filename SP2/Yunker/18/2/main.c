#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "list.h"

int main() {

    setlocale(LC_ALL, "Russian");

    int size = 5;
    char** arr = init(size);

    char** arr2 = init(size);

    qsort(arr, size, sizeof(char*), compare_str);

    printf("sorted arr:\n");

    print_arr(arr, size);

    printf("\noriginal arr:\n");
    print_arr(arr2, size);

    free_arr(arr, size);
    free_arr(arr2, size);

    return 0;
}