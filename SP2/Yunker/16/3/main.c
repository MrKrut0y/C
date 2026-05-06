#include <stdio.h>
#include "list.h"
#include <locale.h>
#include <string.h>
#include <windows.h>

int main() {           // 7

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TYPE temp[NSTR];
    puts("enter the line: ");
    fgets(temp, NSTR-1, stdin);

    int len = strlen(temp);
    if (len > 0 && temp[len-1] == '\n') {
        temp[len-1] = '\0';
        len--;
    }

    /*for (int i=0; i<len; i++) {
        enQueue(&que, temp[i]);
    }

    display(&que);*/

    if (len == 0) {
        printf("Строка пуста\n");
        return 0;
    }

    int isPal = is_palindrom(temp, len);

    if (isPal) {
        printf("\nPalindrom\n");
    } else {
        printf("\nnot palindrom\n");
    }

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}