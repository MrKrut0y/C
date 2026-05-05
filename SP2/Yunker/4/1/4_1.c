#include <stdio.h>
#include <locale.h>

#include "functions4.c"

int main() {

    setlocale(LC_ALL, "Russian");

    double * ptr_array;
    int size;

    printf("Введите размер массива > ");
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

    return 0;
}
