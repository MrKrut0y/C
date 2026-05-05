#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int sum, x, zero, b;

    printf("Введите последовательность целых чисел\n");

    while (1) {
        scanf("%d", x);

        if (x == -9999) {
            break;
        }

        if (zero<2) {
            zero++;
            if (zero == 1) {
                b = 1;
            } 
            else if (zero == 2) {
                b = 0;
            }
        }
        else if (b) {
            sum += x;
        }
    }

    if (zero < 2) {
        printf("должно быть два нуля!\n");
        return 1;
    }

    printf("Сумма %d", sum);

    return 0;
}