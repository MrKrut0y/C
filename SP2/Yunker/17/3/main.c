#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

//#define K 10
//#define N 100
#define H 20

int main() {

    srand(time(NULL));

    int N, MIN, MAX;

    printf("how many numbers\n");
    scanf("%d", &N);

    printf("enter the interval\n");
    printf("min\n");
    scanf("%d", &MIN);
    printf("max\n");
    scanf("%d", &MAX);
    
    int K = MAX - MIN + 1;

    int* counter = (int*)calloc(K, sizeof(int));
    if (counter == NULL) {
        return 1;
    }

    int* array = (int*)malloc(N * sizeof(int));
    if (array == NULL) {
        free(counter);
        return 1;
    }
    
    for (int i=0; i<N; i++) {
        array[i] = MIN + rand() % K;
    }

    for (int i=0; i<N; i++) {
        counter[array[i] - MIN]++;
    }

    build_histogram(counter, H, K);

    free(array);
    free(counter);
    
    printf("\nPress Enter to exit...");
    getchar();
    getchar();
    
    return 0;
}