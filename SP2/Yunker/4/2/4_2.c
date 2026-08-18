#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "functions4_2.c"

int main() {

    setlocale(LC_ALL, "Russian");

    double *ptr_array;
    int size;

    printf("¬ведите размер массива > ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    full_elements(ptr_array, size); // заполнение
    put_elements(ptr_array, size); // вывод
    calc_elements(ptr_array, size); // обработка и вывод нового
    
    free(ptr_array);
    ptr_array = NULL;

    printf("\nѕам€ть успешно освобождена\n");

    return 0;
}
