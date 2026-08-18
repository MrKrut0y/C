#include <stdio.h>
#include <locale.h>

void sum_digits(int *x) {
    int y = *x;
    int sum = 0;
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }
    *x = sum;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int x;

    printf("??????? ????? \n");
    scanf("%d", &x);

    sum_digits(&x);

    printf("%d", x);

    return 0;
}
