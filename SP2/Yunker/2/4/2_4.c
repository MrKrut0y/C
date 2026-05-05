#include <stdio.h>
#include <locale.h>

void print_date(int d, int m, int y, int k) {
    if (k == 0) {
        printf("%02d.%02d.%02d", d, m, y % 100);
    }
    else if (k == 1) {
        printf("%02d.%02d.%04d", d, m, y);
    }
    else if (k == 2) {
        printf("%04d.%02d.%02d", y, m, d);
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    int d, m, y, k;

    printf("„етыре числа:\nХ первое число -- номер дн€ в мес€це,\nХ второе число -- номер мес€ца,\nХ третье число -- год,\nХ четвЄртое число -- формат.\n\n");
    scanf("%d %d %d %d", &d, &m, &y, &k);

    print_date(d, m, y, k);

    return 0;
}