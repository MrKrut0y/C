#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int ameba = 1;
    int k;
    int c, a;
    printf("Количество часов ");
    scanf("%d", &k);

    a = k / 3;
    c = pow(2, a);

    printf("Количество амёб %d", c);

    return 0;
}