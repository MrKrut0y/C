#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int a, b;

    int *p_1;
    int *p_2;

    double d;

    double *p_dbl;

    a = 7;
    b = 3;

    p_1 = &a;
    p_2 = &b;
    p_dbl = &d;

    *p_dbl = (double)*p_1 / (double)*p_2;
    printf("%.2f", *p_dbl);

    return 0;
}