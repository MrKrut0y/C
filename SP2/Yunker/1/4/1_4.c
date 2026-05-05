#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    int n, m;
    int num = 1;
    
    printf("¬ведите через пробел n и m: ");
    scanf("%d %d", &n, &m);
    
    int arr[n][m];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = 0;
        }
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while(top <= bottom && left <= right) {
        for(int j = left; j <= right && num <= n * m + 10; j++) {
            arr[top][j] = num++;
        }
        top++;

        for(int i = top; i <= bottom && num <= n * m + 10; i++) {
            arr[i][right] = num++;
        }
        right--;

        if(top <= bottom) {
            for(int j = right; j >= left && num <= n * m + 10; j--) {
                arr[bottom][j] = num++;
            }
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top && num <= n * m + 10; i--) {
                arr[i][left] = num++;
            }
            left++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    return 0;
}