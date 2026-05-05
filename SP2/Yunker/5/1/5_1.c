#include <stdio.h>
#include <locale.h>

void deleteElement(int arr[], int *length, int index) {

    for (int i = index + 1; i < *length; i++) {
        arr[i - 1] = arr[i];
    }

    (*length)--;

    printf("Element with index %d deleted.\n", index);
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Удаление элемента из середины массива
    printf("Delete element from the middle of the array\n");
    int arr1[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int length1 = 10;
    printf("Original array: ");
    printArray(arr1, length1);
    int middle = length1/2;
    printf("Deleting element at index %d (value: %d)\n", middle, arr1[middle]);
    deleteElement(arr1, &length1, middle);
    printf("Array after deletion: ");
    printArray(arr1, length1);
    printf("New length: %d\n", length1);
    printf("\n");


    // Удаление первого элемента
    printf("Delete first element\n");
    int arr2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int length2 = 10;
    int first_index = 0;
    printf("Original array: ");
    printArray(arr2, length2);
    printf("Deleting element at index %d (value: %d)\n", first_index, arr2[first_index]);
    deleteElement(arr2, &length2, first_index);
    printf("Array after deletion: ");
    printArray(arr2, length2);
    printf("New length: %d\n", length2);
    printf("\n");


    // Удаление последнего элемента в массиве максимальной длины
    printf("Delete last element in array of maximum length\n");
    int arr3[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int length3 = 10;
    int last_index = length3-1;
    printf("Original array: ");
    printArray(arr3, length3);
    printf("Deleting element at index %d (value: %d)\n", last_index, arr3[last_index]);
    deleteElement(arr3, &length3, last_index);
    printf("Array after deletion: ");
    printArray(arr3, length3);
    printf("New length: %d\n", length3);
    printf("\n");


    // Удаление единственного элемента
    printf("Delete the only element\n");
    int arr4[1] = {10};
    int length4 = 1;
    int index = 0;
    printf("Original array: ");
    printArray(arr4, length4);
    printf("Deleting element at index %d (value: %d)\n", index, arr4[index]);
    deleteElement(arr4, &length4, index);
    printf("Array after deletion: ");
    if (length4 > 0) {
        printArray(arr4, length4);
    } else {
        printf("Array is empty\n");
    }
    printf("New length: %d\n", length4);
    printf("\n");

    return 0;
}
