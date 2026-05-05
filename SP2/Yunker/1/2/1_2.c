#include <stdio.h>
#include <locale.h>


int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    printf("¬ведите размер массива\n");
    scanf("%d", &n);

    int arr[n][n];

    int md = 1;
    int sd = 1;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%2d", arr[i][j]);
            if (i == j) {
                md *= arr[i][j];
            }
            if (j == n - i - 1) {
                sd *= arr[i][j];
            }
        }
        printf("\n");
    }

    printf("\n");

    if (md > sd) {
        printf("%d %d", md, sd);
    }
    else {
        printf("%d %d", sd, md);
    }
    
    return 0;
}