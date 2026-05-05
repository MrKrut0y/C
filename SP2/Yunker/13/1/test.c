#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "13.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    char text[20][81] = {
        "Исходный текст не модифицировать."
    };

    int result = find_words_by_length(text, 1, 6, 8);

    if (result == 1) {
        printf("Тест пройден (найдено %d слова)\n", result);
    } else {
        printf("Тест не пройден (ожидалось 2, найдено %d)\n", result);
    }

    while (0) { 
        
    }
    printf("Нажмите Enter, чтобы выйти...");
    fflush(stdout);
    getchar();

    return 0;
}