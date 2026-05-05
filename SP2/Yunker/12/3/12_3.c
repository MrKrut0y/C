#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

const char* morse_table[26] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--.."   // Z
};

const char* char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    }
        
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    }
        
    return NULL;
}

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
    
    for (int i = 0; i < m; i++) {
        gets(text[i]);
    }
    
    for (int i = 0; i < m; i++) {
        int first_char = 1;
        int printed = 0;
        
        for (int j = 0; text[i][j] != '\0'; j++) {
            const char* morse = char_to_morse(text[i][j]);
            
            if (morse != NULL) {
                if (!first_char) {
                    printf(" ");
                }
                printf("%s", morse);
                first_char = 0;
                printed = 1;
            }
        }
        
        if (printed) {
            printf("\n");
            has_output = 1;
        }
    }
    
    if (!has_output) {
        printf("no solution\n");
    }
    
    return 0;
}