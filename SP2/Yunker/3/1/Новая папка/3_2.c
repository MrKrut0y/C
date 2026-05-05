#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#include "functions.c"

/*
#include "full_elements.c"
#include "put_elements.c"
#include "calc_elements.c"
#include "sum_element.c"
#include "find_element.c"

/*/// 1
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
        double new = ptr_array[i] += ptr_array[n-1];
        printf("| %2d | %5.2f | %6.2f |\n", i, orig, new);
        ptr_array[i] = new;
    }
}

// 2
// 1)
double sum_element(double *ptr_array, int begin, int end) {
    double sum = 0.0;

    for (int i = begin;i<=end;i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// 2)
int find_element(double *ptr_array, int n, double element) {
    for (int i=0;i<n;i++) {
        if (ptr_array[i] == element) {
            return i;
        }
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

    full_elements(array, size);
    put_elements(array, size);
    printf("\n");
    calc_elements(array, size);

    // 2
    // 1)
    int begin, end;
    printf("\nВедите индекс begin: ");
    scanf("%d", &begin);
    printf("Ведите индекс end: ");
    scanf("%d", &end);
    double sum = sum_element(array, begin, end);
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

    return 0;
}
