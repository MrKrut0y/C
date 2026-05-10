#include <stdio.h>
#include <locale.h>

int power_of_two(int n) {

    if (n < 0 || n > 30) {
        printf("error");
        return -1;
    }

    if (n == 0) return 1;

    return 2 * power_of_two(n - 1);
}

int main() {

    setlocale(LC_ALL, "Russian");

    int result = power_of_two(0); // Базовый случай
    printf("%d\n", result);

    result = power_of_two(1); // Простой случай
    printf("%d\n", result);

    result = power_of_two(5); // Нормальный случай
    printf("%d\n", result);
    
    result = power_of_two(10); // Большее значение
    printf("%d\n", result);
    
    result = power_of_two(31); // Ошибка
    printf("%d\n", result);
    
    result = power_of_two(-3); // Ошибка
    printf("%d\n", result);

    return 0;
}