#include <stdio.h>
#include <locale.h>

int recurs_func(int n) {

    if (n<0 || n>15) return 0;

    if (n == 0) return 1;

    return recurs_func(n-1) + recurs_func(n-2) + recurs_func(n-3);
}

int main() {      // Задача "Подъём по лестнице"

    setlocale(LC_ALL, "Russian");

    int n;

    printf("enter the number of steps:\n");
    scanf("%d", &n);

    int result = recurs_func(n);
    printf("%d", result);

    return 0;
}