#include <stdio.h>
#include <locale.h>


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

    int arr[] = {3,4,67,3,6,31,1,8};
    int *ptrarr = arr;
    int n = 8;

    printf("\nПузырьковый метод:\n");
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
    printf("\n\n");    

    return 0;
}
