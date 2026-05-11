#include <stdio.h>
#include <string.h>
#include "list.h"

const char delimiters[] = " !\"_;:?_.,-";

int is_delimiter(char c) {
    if (c == '\0') return 1;
    for (int i=0; delimiters[i] != '\0'; i++) {
        if (c == delimiters[i]) {
            return 1;
        }
    }
    return 0;
}

int strToWords(const char str[81], char words[40][21]) {
    int word_count = 0;
    int char_count = 0;
    int in_word = 0;

    for (int i=0; str[i] != '\0'; i++) {
        if (is_delimiter(str[i])) {
            if (in_word) {
                words[word_count][char_count] = '\0';
                word_count++;
                char_count = 0;
                in_word = 0;
                if (word_count >= 40) break;
            }
        } else {
            in_word = 1;
            
            if (char_count < 20) {
                words[word_count][char_count] = str[i];
                char_count++;
            }
        }
    }

    if (in_word && word_count < 40) {
        words[word_count][char_count] = '\0';
        word_count++;
    }

    return word_count;
}

int findString(const char stringList[20][21], int count, const char str[21]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(stringList[i], str) == 0) {
            return i;
        }
    }
    return -1; 
}