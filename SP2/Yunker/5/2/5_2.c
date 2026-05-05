#include <stdio.h>
#include <locale.h>

#define MAX_SIZE 10

int findMinElements(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 1;
    int min = arr[0];
    pos[0] = 0;

    for (int i=1;i<size;i++) {
        if (min > arr[i]) {
            min = arr[i];
            count = 1;
            pos[0] =i;
        } else if (min == arr[i]) {
            pos[count] = i;
            count++;
        }
    }
    return count;
}


int findMinElements1(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 1;
    int min = arr[0];
    pos[0] = 0;

    for (int i=1;i<size;i++) {
        if (min > arr[i]) {
            min = arr[i];
            //count = 1;
            pos[0] =i;
        } else if (min == arr[i]) {
            pos[count] = i;
            count++;
        }
    }
    return count;
}


int findMinElements2(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 1;
    int min = 0; // 0
    pos[0] = 0;

    for (int i=1;i<size;i++) {
        if (min > arr[i]) {
            min = arr[i];
            count = 1;
            pos[0] =i;
        } else if (min == arr[i]) {
            pos[count] = i;
            count++;
        }
    }
    return count;
}


int findMinElements3(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 1;
    int min = arr[0]; 
    pos[0] = 0;

    for (int i=1;i<size;i++) {
        if (min < arr[i]) {  // max
            min = arr[i];
            count = 1;
            pos[0] =i;
        } else if (min == arr[i]) {
            pos[count] = i;
            count++;
        }
    }
    return count;
}


int findMinElements4(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 1;
    int min = arr[0]; 
    pos[0] = 0;

    for (int i=1;i<size-1;i++) { // -1
        if (min > arr[i]) {  
            min = arr[i];
            count = 1;
            pos[0] =i;
        } else if (min == arr[i]) {
            pos[count] = i;
            count++;
        }
    }
    return count;
}


int findMinElements5(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 0; // 0
    int min = arr[0]; 
    pos[0] = 0;

    for (int i=1;i<size-1;i++) {
        if (min > arr[i]) {  
            min = arr[i];
            //count = 1;
            pos[0] =i;
        } else if (min == arr[i]) {
            pos[count] = i;
            //count++;
        }
    }
    return count;
}


int* findMinElements6(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 1;
    int min = arr[0]; 
    pos[0] = arr[0];

    for (int i=1;i<size;i++) {
        if (min > arr[i]) {  
            min = arr[i];
            count = 1;
            pos[0] =arr[i];
        } else if (min == arr[i]) {
            pos[count] = arr[i];
            count++;
        }
    }
    return pos;
}


int findMinElements7(const int arr[MAX_SIZE], int size, int pos[MAX_SIZE]) {
    int count = 1;
    int min = arr[0]; 
    pos[0] = 0;

    for (int i=1;i<=size;i++) {
        if (min > arr[i]) {  
            min = arr[i];
            count = 1;
            pos[0] =i;
        } else if (min == arr[i]) {
            pos[count] = i;
            count++;
        }
    }
    return count;
}


int main() {

    setlocale(LC_ALL, "Russian");

    int arr[] = {3,5,26,7,1,9,56,1,90,10}; 
    int size = 10;
    int pos[MAX_SIZE];


    printf("Работоспособный вариант\n");
    int r1 = findMinElements(arr, size, pos);
    printf("%d",r1);
    printf("\n\n");


    printf("Изначально кол-во минимальных элементов не обнуляется\n");
    int r2 = findMinElements1(arr, size, pos);
    printf("%d",r2);
    printf("\n\n");


    printf("Изначально считается, что минимальным элементом является 0\n");
    int r3 = findMinElements2(arr, size, pos);
    printf("%d",r3);
    printf("\n\n");


    printf("Ищем не мин., а макс\n");
    int r4 = findMinElements3(arr, size, pos);
    printf("%d",r4);
    printf("\n\n");


    printf("Рассматриваются не все элементы массива\n");
    int r5 = findMinElements4(arr, size, pos);
    printf("%d",r5);
    printf("\n\n");


    printf("кол-во минимальных элементов всегда 0\n");
    int r6 = findMinElements5(arr, size, pos);
    printf("%d",r6);
    printf("\n\n");


    printf("Возвращаются не индексы, а значения минимальных элементов\n");
    int* r7 = findMinElements6(arr, size, pos);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d", r7[i]);
        if (i < MAX_SIZE - 1) printf(", ");
    }
    printf("\n\n");


    printf("Выход за пределы массива\n");
    int r8 = findMinElements7(arr, size, pos);
    printf("%d",r8);
    printf("\n\n");





    return 0;
}
