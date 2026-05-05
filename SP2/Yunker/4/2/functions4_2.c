#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

// 1
double* full_elements(double *ptr_array, int n) {
    srand(time(NULL));

    for (int i=0;i<n;i++) {
        ptr_array[i] = (double)((rand() % 201) - 100) / 100.0;
    }

    return ptr_array;
}

void put_elements(double *ptr_array, int n) {
    for (int i=0;i<n;i++) {
        printf("%.2f\n", ptr_array[i]);
    }
    printf("\n");
}

void calc_el(double *ptr_array, int n) {
    for(int i=0; i<n; i++) {
        double orig = ptr_array[i];
        printf("| %2d | %6.2f |\n", i, orig);
    }
    printf("\n");
}

double* calc_elements(double *ptr_array, int n) {  // 11.	к каждому элементу массива прибавить значение последнего элемента;
    double *new_array = (double*)malloc(n * sizeof(double)); // создание нового массива
    if (new_array == NULL) {
        printf("eror\n");
        return NULL;
    }
    
    for(int i = 0; i < n; i++) {
        new_array[i] = ptr_array[i] + ptr_array[n-1]; // вывод
        printf("| %2d | %4.2f |\n", i, new_array[i]);
    }
    printf("\n");

    return new_array;
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

// 3     11)
int find_minimal(double *ptr_array, int n, double a) {  
    int min_i = -1;
    double min;

    for (int i=0;i<n;i++) {
        if (ptr_array[i] > a && ptr_array[i] > 0) {
            min = ptr_array[i];
            min_i = i;
            break;
        }
    }

    if (min_i == -1) {
        return -1;
    }

    for (int i = min_i+1;i<n;i++) {
        if (ptr_array[i] > a && ptr_array[i] > 0 && ptr_array[i] < min) {
            min = ptr_array[i];
            min_i = i;
        }
    }

    return min_i;
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

int find_max_index(double *ptr_array, int n) {
    double max = ptr_array[0];
    int max_i = 0;
    for (int i=1;i<n;i++) {
        if (ptr_array[i] > max) {
            max = ptr_array[i];
            max_i = i;
        }
    }
    return max_i;
}

double* delete_2max(double *ptr_array, int size, int max_i) { // удаление 2 максимальных элементов
    if (size <= 2) 
    {
        return NULL;
    }

    int max_i2 = 0;
    double max_2 = -1;

    for (int i=0;i<size;i++) {
        if (i!=max_i && i>max_2) {
            max_i2 = i;
            max_2 = ptr_array[i];
            break;
        }
    }

    double *new_array = (double*)malloc((size - 2) * sizeof(double));
    if (new_array == NULL) {
        printf("eror\n");
        return NULL;
    }

    int j= 0;
    for (int i=0;i<size;i++) {
        if (i != max_i && i!=max_i2) {
            new_array[j++] = ptr_array[i];
        }
    }
    printf("Удалены элементы с индексами %d и %d\n", max_i, max_i2);
    return new_array;

}

double* insert(double *ptr_array, int size, int max_i, double num) { // 5. Вставка перед максимальным элементом.
    double *new_array = (double*)malloc((size+1) * sizeof(double));
    if (new_array == NULL) {
        printf("eror\n");
        return NULL;
    }

    int j= 0;
    for (int i=0;i<size+1;i++) {
        if (i== max_i-1) {
            new_array[j++] = num;
        }
        else {
            new_array[j++] = ptr_array[i];
        }
    }
    
    return new_array;
}