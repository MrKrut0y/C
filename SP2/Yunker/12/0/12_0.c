#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char text[20][81];
    int m;
    int word_count = 0;
    
    scanf("%d", &m);
    
    if (m < 1 || m > 20) {
        printf("invalid input data");
        return 0;
    }

    while (getchar() != '\n');

    for (int i = 0; i < m; i++) {
        gets(text[i]);
    }

    for (int i = 0; i < m; i++) {
        char word[81];
        int word_len = 0;
        
        for (int j = 0; text[i][j] != '\0'; j++) {
            char c = text[i][j];

            if (c == ' ' || c == ',' || c == '.') {
                if (word_len > 0) {
                    word[word_len] = '\0';
                    printf("%s\n", word);
                    word_count++;
                    word_len = 0;
                }
            } else {
                word[word_len++] = c;
            }
        }

        if (word_len > 0) {
            word[word_len] = '\0';
            printf("%s\n", word);
            word_count++;
        }
    }

    if (word_count == 0) {
        printf("no solution");
    }
    
    return 0;
}