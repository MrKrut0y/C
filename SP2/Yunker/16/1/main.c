#include <stdio.h>
#include "list.h"
#include <locale.h>
#include <string.h>
#include <windows.h>

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    stack s;
    s.top = -1;

    char x[NMAX+1];
    printf("¬ведите строку: ");
    fgets(x, sizeof(x), stdin);

    int len = strlen(x);
    if (len > 0 && x[len-1] == '\n') {
        x[len-1] = '\0';
        len--;
    }

    for (int i=0; i<len; i++) {
        push(&s, x[i]);
    }

    display(&s);

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}