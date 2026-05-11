#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "list.h"

int main() {
    setlocale(LC_ALL, "Russian");

    char str[81];

    if (fgets(str, 81, stdin) == NULL) {
        printf("no solution\n");
        return 0;
    }

    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }

    int M;
    if (scanf("%d", &M) != 1) {
        printf("no solution\n");
        return 0;
    }

    char dictionary[20][21];

    for (int i=0; i<20; i++) {
        dictionary[i][0] = '\0';
    }

    for (int i=0; i<M; i++) {
        if (scanf("%20s", dictionary[i]) != 1) {
            break;
        }
    }

    char words[40][21];
    int word_count = strToWords(str, words);

    int error_count = 0;
    for (int i=0; i<word_count; i++) {
        if (findString(dictionary, M, words[i]) == -1) {
            error_count++;
        }
    }

    printf("%d\n", error_count);

    return 0;
}