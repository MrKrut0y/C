#include <stdio.h>
#include "list.h"
#include <locale.h>
#include <string.h>
#include <windows.h>

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    queue_list que;  // объявление и инициализация очереди
    que.end=que.begin= que.queue= NULL;

    TYPE temp[NSTR];
    puts("enter the line: ");
    fgets(temp, NSTR-1, stdin);

    int len = strlen(temp);
    if (len > 0 && temp[len-1] == '\n') {
        temp[len-1] = '\0';
    }

    for (int i=0; temp[i] != '\0'; i++) {
        enQueue(&que, temp[i]);
    }

    display(&que);

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}