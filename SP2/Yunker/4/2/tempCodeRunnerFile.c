#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "functions4_2.c"

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
    //calc_elements(ptr_array, size); // обработка и вывод нового
    int max_i = find_max_index(ptr_array, size);
    printf("Индекс максимального: %d\n", max_i);
    double *new_array = delete_2max(ptr_array, size, max_i); // удаление 2 максимальных элементов
    
    printf("Новый массив после удаления:\n");
    put_elements(new_array, size - 2); // вывод
    free(new_array); 
    
    free(ptr_array);
    ptr_array = NULL;

    printf("\nПамять успешно освобождена.\n");

    return 0;
}
