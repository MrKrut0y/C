#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

    setlocale(LC_ALL, "Russian");

    char fname[20] = "temp.txt";
    FILE *out;

    double start = 2.0;
    double end = 4.1;
    double step;

    printf("Выберите действие\n");
    printf("1) запись в новый файл\n2) дозапись в существующий\n");
    int ch;
    scanf("%d", &ch);

    if (ch==1) {

        puts("Создание файла");
        if ((out = fopen(fname, "w")) == NULL) {
            printf("Ошибка открытия файла для записи");
            return 1;
        }

    } else if (ch==2) {

        if ((out = fopen(fname, "a")) == NULL) {
            printf("Ошибка открытия файла для записи");
            return 1;
        }
    }
    else {
        return 1;
    }

    fprintf(out, "Функция: y = | lg x | - (x-2)^2\n");
    printf("Введите шаг табуляции: \n");
    scanf("%lf", &step);

    fprintf(out, "______________\n");
    fprintf(out, "|  x  |   f(x)   |\n");
    fprintf(out, "______________\n");

    for (double x = start; x <= end + 0.0001; x += step) {
        double y = fabs(log10(x)) - pow(x - 2, 2);
        fprintf(out, "| %.1f | %8.3f |\n", x, y);
    }
    fprintf(out, "______________\n");
    fclose(out);


    return 0;
}
