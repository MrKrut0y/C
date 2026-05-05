#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Russian");


    int n;

    printf("¬ведите количество\n");
    scanf("%d", &n);
    
    if (n <= 0) {
        return 0;
    }

    int arr[n];

    printf("¬ведите числа\n");

    for (int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }    
    }

    printf("%d", arr[0]);

    for (int i=1;i<n;i++) {
        if (arr[i] != arr[i-1]) {
            printf(" %d", arr[i]);
        }
    }
    
    printf("\n");
    return 0;
}