#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#include "functions4.c"

/*
// 1
double* full_elements(double *ptr_array, int n) {
    srand(time(NULL));

    for (int i=0;i<n;i++) {
        ptr_array[i] = (double)((rand() % 1000) - 500) / 10.0;
    }

    return ptr_array;
}

void put_elements(double *ptr_array, int n) {
    for (int i=0;i<n;i++) {
        printf("%.2f\n", ptr_array[i]);
    }
}

double* calc_elements(double *ptr_array, int n) {
    for(int i=0; i<n; i++) {
        double orig = ptr_array[i];
        printf("| %2d | %6.2f |\n", i, orig);
    }
}

// 4      24
int ind(double *ptr_array, int n, int type) {

    if (n < 2) {
        return -1;
    }

    if (type == 1) {
        for (int i=0;i<n-1;i++) {
            if ((ptr_array[i] > 0 && ptr_array[i + 1] < 0) || (ptr_array[i] < 0 && ptr_array[i + 1] > 0)) {
                return i;
            }
        }
        return -1;
    }

    if (type == 0) {
        for (int i=n-2;i>=0;i--) {
            if ((ptr_array[i] > 0 && ptr_array[i + 1] < 0) || (ptr_array[i] < 0 && ptr_array[i + 1] > 0)) {
                return i;
            }
        }
        return -1;
    }
    return -1;
}
*/

int main() {
    setlocale(LC_ALL, "Russian");

    // 1
    int size;

    printf("Введите размер массива > ");
    scanf("%d", &size);
    double array[size];

    printf("\n");
    full_elements(array, size); //1
    printf("\n");
    put_elements(array, size);  //2
    printf("\n");
    calc_elements(array, size); //3
    printf("\n");

    // 2
    // 1)
    int begin, end;
    printf("\nВедите индекс begin: ");
    scanf("%d", &begin);
    printf("Ведите индекс end: ");
    scanf("%d", &end);
    double sum = sum_element(array, begin, end);  //4
    printf("Сумма элементов от индекса %d до %d: %.2f (после обновления массива)\n", begin, end, sum);

    // 2)
    double a;

    printf("Введите элемент а: ");
    scanf("%lf", &a);

    // поиск после обновления массива
    int found_index = find_element(array, size, a);

    if (found_index != -1) {
        printf("Элемент %.2f найден по индексу: %d\n", a, found_index);
    } else {
        printf("Элемент %.2f не найден\n", a);
    }

    // 4
    int first_index = ind(array, size, 1);
    int last_index = ind(array, size, 0);

    if (first_index != -1) {
        printf("Индекс первого элемента массива следующих за котором элемент имеет другой знак: %d\n", first_index);
    } else {
        printf("Первая знакопеременная позиция не найдена\n");
    }


    // 3

    int min_i = function3(array, size, a);
    if (min_i != -1) {
        printf("Индекс минимального положительного элемента, большего заданного значения a (%.2f): %d\n", a, min_i);
    } else {
        printf("Нет положительных элементов, больших чем %.2f\n", a);
    }

    if (last_index != -1) {
        printf("Индекс последнего элемента массива следующих за котором элемент имеет другой знак: %d\n", last_index);
    } else {
        printf("Последняя знакопеременная позиция не найдена\n");
    }




    return 0;
}

