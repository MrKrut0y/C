#include <stdio.h>
#include <locale.h>
#include <limits.h>

int main() {
    setlocale(LC_ALL, "Russian");

    int n, m;
    int sum = 0;

    printf("¬ведите через пробел n и m: ");
    scanf("%d %d", &n, &m);

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int max_sum = INT_MIN, min_sum = INT_MAX;
    int max_col = 0, min_col = 0;

    for (int j = 0; j < m; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += arr[i][j];
        }

        if (col_sum > max_sum) {
            max_sum = col_sum;
            max_col = j;
        }

        if (col_sum < min_sum) {
            min_sum = col_sum;
            min_col = j;
        }
    }
    
    if (min_col != max_col) {
        for (int i = 0; i < n; i++) {
            int temp = arr[i][min_col];
            arr[i][min_col] = arr[i][max_col];
            arr[i][max_col] = temp;
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}