#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

char delimiters[] = " !'\"();:?-. ,";

int is_word_char(char c) {
    return isalnum((unsigned char)c);
}

int is_delimiter(char c) {
    for (int i=0;delimiters[i] != '\0';i++) {
        if (c == delimiters[i]) {
            return 1;
        }
    }
    return 0;
}

int find_words_by_length(char text[20][81], int m, int min, int max) {
    
    int word_count = 0;

    for (int i=0;i<m;i++) {
        char word[81];
        int word_len = 0;
        int is_invalid = 0;

        for (int j=0;text[i][j] != '\0';j++) {
            char c = text[i][j];
 
            if (is_delimiter(c)) {
                if (word_len > 0 && !is_invalid) {
                    word[word_len] = '\0';
                    if (word_len >= min && word_len <= max) {
                        printf("%s\n", word);
                        word_count++;
                    }
                }
                word_len = 0;
                is_invalid = 0;
            } 
            else if (is_word_char(c)) {
                if (word_len < 80) {
                    word[word_len++] = c;
                }
            } 
            else {
                is_invalid = 1;
            }
        }
    }
    return word_count;
}
