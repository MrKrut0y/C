#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

    setlocale(LC_ALL, "Russian");

    FILE* in;
    int a;
    int n = 0;
    int sum = 0;
    //puts("Укажите файл для чтения");
    in = fopen ("number.txt", "rt");
    if (in == NULL) {
        printf("Ошибка открытия");
        return 0;
    }
    while (fscanf(in, "%d", &a) == 1) {
         sum += a;
         n++;
    }
    fclose(in);

    printf("AVG: %d", sum/n);

    return 0;
}
