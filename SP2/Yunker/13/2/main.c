#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "13.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char new_name[41];
    char students[30][41];
    int m;

    printf("Фамилия для вставки: ");
    scanf("%s", new_name);

    printf("Количество студентов: ");
    scanf("%d", &m);

    if (m <= 0) {
        printf("no solution\n");
        return 0;
    }

    printf("Введите %d фамилий по алфавиту:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%s", students[i]);
    }

    int result = insert_student(students, &m, new_name);

    if (result == -1) {
        printf("no solution\n");
    } else if (result == 0) {
        printf("invalid input data\n");
    } else {
        printf("\nОбновленный список:\n");
        for (int i = 0; i < m; i++) {
            printf("%s\n", students[i]);
        }
    }

    printf("\nНажмите Enter, чтобы выйти...");
    while (getchar() != '\n'); 
    getchar();

    return 0;
}