#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    
    double start = 2.0;
    double end = 4.1;
    double step;
    
    printf("Функция: y = | lg x | - (x-2)^2\n");
    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);
    
    printf("______________\n");
    printf("|  x  |   f(x)   |\n");
    printf("______________\n");
    
    for (double x = start; x <= end + 0.0001; x += step) {
        double y = fabs(log10(x)) - pow(x - 2, 2);
        printf("| %.1f | %8.3f |\n", x, y);
    }
    
    printf("______________\n");
    
    return 0;
}