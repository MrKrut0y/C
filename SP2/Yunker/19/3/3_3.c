#include <stdio.h>
#include <locale.h>

int recurs_func(int n, int m) {

    if (n == 0 || m == 0) return 1;

    return recurs_func(n-1, m) + recurs_func(n, m-1);
}

int main() {   // Задача "Пути в решётке"

    setlocale(LC_ALL, "Russian");

    int n, m;

    scanf("%d %d", &n, &m);

    int result = recurs_func(n, m);

    printf("%d", result);

    return 0;
}