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
    int has_output = 0;
    
    scanf("%d", &m);
    
    if (m < 1 || m > 20) {
        printf("invalid input data");
        return 0;
    }
    
    while (getchar() != '\n');
    
    for (int i =0; i<m; i++) {
        gets(text[i]);
    }
    
    for (int i=0; i<m; i++) {
        int j = 0;
        while (text[i][j] == ' ') {
            j++;
        }
        
        if (text[i][j] == '\0') {
            continue;
        }
        
        int new_sent = 1;
        int printed = 0;
        
        while (text[i][j] != '\0') {
            char c = text[i][j];
            
            if (new_sent) {
                printf("****");
                new_sent = 0;
                printed = 1;
            }

            if (c == ' ') {
                printf("*");
            } else {
                printf("%c", c);
            }
            printed = 1;

            if (c == '.' || c == '?' || c == '!') {
                if (text[i][j + 1] == ' ' || text[i][j + 1] == '\0') {
                    new_sent = 1;
                }
            }
            j++;
        }
        
        if (printed) {
            printf("\n");
            has_output = 1;
        }
    }
    if (!has_output) {
        printf("no solution");
    }
    
    return 0;
}