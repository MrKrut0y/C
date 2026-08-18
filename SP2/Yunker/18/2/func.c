#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define N 5

char** init(int size) {
    
    static char *sports[] = {"hockey", "football", "cricket", "tennis", "golf"};

    char** arr = (char**)malloc(size * sizeof(char*));

    for (int i=0; i<size; i++) {
        arr[i] = (char*)malloc((strlen(sports[i % N])+1)* sizeof(char));
        strcpy(arr[i], sports[i%N]);
    }

    return arr;
}

void print_arr(char** arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%s\n", arr[i]);
    }
}

void free_arr(char** arr, int size) {
    for (int i=0; i<size; i++) {
        free(arr[i]);
    }
    free(arr);
}

int compare_str(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}