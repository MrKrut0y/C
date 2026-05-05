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
    int index;
    int current_index = 0;
    int found = 0;
    char result[81] = "";
    
    scanf("%d", &index);
    scanf("%d", &m);
    
    if (m < 1 || m > 20) {
        printf("invalid input data");
        return 0;
    }

    while (getchar() != '\n');

    for (int i = 0; i < m; i++) {
        gets(text[i]);
    }

    for (int i = 0; i < m && !found; i++) {
        char word[81];
        int word_len = 0;
        
        for (int j = 0; text[i][j] != '\0'; j++) {
            char c = text[i][j];

            if (c == ' ' || c == ',' || c == '.') {
                if (word_len > 0) {
                    if (current_index == index) {
                        word[word_len] = '\0';
                        for (int k = word_len - 1; k >= 0; k--) {
                            printf("%c", word[k]);
                        }
                        found = 1;
                        break;
                    }
                    current_index++;
                    word_len = 0;
                }
            } else {
                word[word_len++] = c;
            }
        }

        if (word_len > 0 && !found) {
            if (current_index == index) {
                word[word_len] = '\0';
                for (int k = word_len - 1; k >= 0; k--) {
                    printf("%c", word[k]);
                }
                found = 1;
                break;
            }
            current_index++;
        }
    }  

    if (!found) {
        printf("no solution\n");
    }
    
    return 0;
}