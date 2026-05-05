#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "13.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char text[20][81];
    int min, max, m;

    printf("Введите минимум: \n");
    scanf("%d", &min);
    printf("Введите максимум: \n");
    scanf("%d", &max);
    printf("Введите количество строк\n");
    scanf("%d", &m);

    if (m < 1 || m > 20) {
        printf("invalid input data");
        return 0;
    }

    while (getchar() != '\n');

    for (int i = 0; i < m; i++) {
        gets(text[i]);
    }

    int word_count = find_words_by_length(text, m, min, max);

    if (word_count == 0) {
        printf("no solution\n");
    }

    printf("\n--- Работа завершена ---\n");
    while (getchar() != '\n' && getchar() != EOF); 
    printf("Нажмите Enter, чтобы закрыть окно...");
    getchar();

    return 0;
}