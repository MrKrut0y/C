#include <stdio.h>
#include <locale.h>
#include "list.h"

int main() {

    setlocale(LC_ALL, "Russian");

    int NN, N, M;

    printf("Enter the number of rows (N) [1-10]: ");
    if (scanf("%d", &N) != 1 || N < 1 || N > 10) return 1;

    printf("Enter the max height of row (M) [1-10]: ");
    if (scanf("%d", &M) != 1 || M < 1 || M > 10) return 1;

    printf("Enter the box number to extract [1-9999]: ");
    if (scanf("%d", &NN) != 1 || NN < 1 || NN > 9999) return 1;

    Box* root = startFillingWarehouse(NN, N, M);

    showWarehouse(root, M);

    if (startBoxTransferring(&root, NN, N, M) == 0) {
        printf("no solution\n");
    }

    printf("\nWarehouse after transferring:\n");
    showWarehouse(root, M);

    root = startEmptyingWarehouse(root);

    printf("trying to print a warehouse\n");
    showWarehouse(root, M);
    
    return 0;
}