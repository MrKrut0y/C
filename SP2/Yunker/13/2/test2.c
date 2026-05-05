#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "13.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char students[30][41] = { "Иванов", "Петров" };
    int m = 2;
    char new_student[] = "Иванов"; 

    printf("Вставка фамилии '%s'\n", new_student);
    printf("Исходный список: 1. Иванов, 2. Петров\n\n");

    int res = insert_student(students, &m, new_student);

    if (res == 1) {
        printf("Тест пройден\n");
        for (int i=0;i<m;i++) {
            printf("%d. %s\n", i + 1, students[i]);
        }
    } else {
        printf("Тест не пройден.\n");
    }

    printf("\nНажмите Enter, чтобы выйти...");
    getchar();

    return 0;
}