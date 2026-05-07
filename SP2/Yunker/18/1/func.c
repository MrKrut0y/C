#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define N 5

char** init(int size) {
    
    static char *sports[] = {"golf", "hockey", "foolball", "cricket", "tennis"};

    char** arr = (char**)malloc(size * sizeof(char*));

    for (int i=0; i<size; i++) {
        arr[i] = (char*)malloc(strlen(sports[i % N])* sizeof(char));
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

void change_value(char** arr, int index, const char* new_value) {

    free(arr[index]);

    arr[index-1] = (char*)malloc((strlen(new_value) + 1) * sizeof(char));
    strcpy(arr[index-1], new_value);
}