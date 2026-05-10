#include <stdio.h>
#include <locale.h>

int recurs_func(int n) {

    if (n<=0) return 0;

    if (n == 1) return 1;

    return n + recurs_func(n-1);
}

int main() {              // 7

    setlocale(LC_ALL, "Russian");

    int result = recurs_func(4);
    printf("%d", result);

    return 0;
}