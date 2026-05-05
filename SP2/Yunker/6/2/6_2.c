#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>


int* full_array(int *ptrarr, int n) {
    for (int i=0;i<n;i++) {
        ptrarr[i] = rand() % 100;
    }
    return ptrarr;
}


void sort_bubble(int*ptrarr, int n) {
    int t;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                t = ptrarr[j];
                ptrarr[j] = ptrarr[j+1];
                ptrarr[j+1] = t;
            }
        }
    }
}


void printArr(int*ptrarr, int n) {
    for (int i=0;i<n;i++) {
        printf("%d ", ptrarr[i]);
    }
}


void sort_kokteil(int*ptrarr, int n) {
    int left = 0;
    int right = n-1;
    int t;

    while (left < right) {
        for (int i=left;i<right;i++) {
            if (ptrarr[i] > ptrarr[i+1]) {
                t = ptrarr[i];
                ptrarr[i] = ptrarr[i+1];
                ptrarr[i+1] = t;
            }
        }
        right--;


        for (int i=right;i>left;i--) {
            if (ptrarr[i-1]>ptrarr[i]) {
                t = ptrarr[i-1];
                ptrarr[i-1] = ptrarr[i];
                ptrarr[i] = t;
            }
        }
        left++;
    }
}


void sort_select(int*ptrarr, int n) {
    int t;
    int max;

    for (int i=n-1;i>0;i--) {
        max=0;
        for (int j=1;j<=i;j++) {
            if (ptrarr[j]>ptrarr[max]) {
                max=j;
            }
        }

        if (max!=i) {
            t=ptrarr[i];
            ptrarr[i]=ptrarr[max];
            ptrarr[max]=t;
        }
    }
}


void sort_insert(int*ptrarr, int n) {
    int t;
    int j;

    for (int k=1;k<n;k++) {
        t = ptrarr[k];
        j = k - 1;
        
        while (j>=0 && ptrarr[j]>t) {
            ptrarr[j + 1] = ptrarr[j];
            j--;
        }
        ptrarr[j+1] = t;
    }
}


int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    printf("Введите размер массива-> ");
    scanf("%d", &n);
    
    int *ptrarr = (int*)malloc(n * sizeof(int));
    srand(time(NULL));

    full_array(ptrarr, n);


    int *arr_bubble = (int*)malloc(n * sizeof(int));
    int *arr_kokteil = (int*)malloc(n * sizeof(int));
    int *arr_select = (int*)malloc(n * sizeof(int));
    int *arr_insert = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        arr_bubble[i] = ptrarr[i];
        arr_kokteil[i] = ptrarr[i];
        arr_select[i] = ptrarr[i];
        arr_insert[i] = ptrarr[i];
    }

    clock_t t;
    double time;

    t = clock();
    sort_bubble(arr_bubble, n);
    time = (clock() - t) * 1.0 / CLOCKS_PER_SEC;
    printf("Пузырьковая: %.6f сек\n", time);
    
    t = clock();
    sort_kokteil(arr_kokteil, n);
    time = (clock() - t) * 1.0 / CLOCKS_PER_SEC;
    printf("Шейкерная: %.6f сек\n", time);
    
    t = clock();
    sort_select(arr_select, n);
    time = (clock() - t) * 1.0 / CLOCKS_PER_SEC;
    printf("Выбором: %.6f сек\n", time);
    
    t = clock();
    sort_insert(arr_insert, n);
    time = (clock() - t) * 1.0 / CLOCKS_PER_SEC;
    printf("Вставками: %.6f сек\n", time);
    
    free(ptrarr);
    free(arr_bubble);
    free(arr_kokteil);
    free(arr_select);
    free(arr_insert);

    /*printf("\nПузырьковый метод:\n");
    sort_bubble(ptrarr, n);
    printArr(ptrarr, n);
    printf("\n\n");


    printf("Шейкерная сортировка\n");
    sort_kokteil(ptrarr, n);
    printArr(ptrarr, n);
    printf("\n\n");


    printf("Сортировка простым выбором\n");
    sort_select(ptrarr, n);
    printArr(ptrarr, n);
    printf("\n\n");


    printf("Сортировка вставками\n");
    sort_insert(ptrarr, n);
    printArr(ptrarr, n);
    printf("\n\n");*/  

    return 0;
}
