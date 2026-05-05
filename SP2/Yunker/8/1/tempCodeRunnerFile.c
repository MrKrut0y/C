#include <stdio.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Russian");

    char fname[20] = "number.txt";
    FILE *out;
    puts("Создание файла");
    if ((out = fopen(fname, "wt")) == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0;
    }

    fprintf(out, "%d\n", 5);
    fclose(out);


    puts("Добавление 12,56");

    if ((out = fopen(fname, "a")) == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0;
    }

    fprintf(out, "%.2lf\n", 12.56);
    fclose(out);

    printf("%d\n%.2lf\n", 5, 12.56);

    return 1;
}
