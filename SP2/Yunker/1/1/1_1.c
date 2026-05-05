#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    printf("¬ведите размер массива\n");
    scanf("%d", &n);

    int arr[n][n];

    for (int i=0;i<n;i++) {
        if (i % 2 == 0) {
            for (int j=0;j<n;j++){
                arr[i][j]=j+1;
                printf("%d ",arr[i][j]);
            }
        }
        else {
            for (int j=0;j<n;j++) {
                arr[i][j]=n-j;
                printf("%d ",arr[i][j]);
                }
        }
        printf("\n");
        }


    return 0;
}
