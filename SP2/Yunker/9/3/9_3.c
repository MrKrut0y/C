#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {

    setlocale(LC_ALL, "Russian");   // 22 Вывести слова в обратном порядке
    char new_fname[50];
    char line[50];
    char words[50][100];
    int word_count;

    FILE *in, *out;

    in = fopen("winter.txt", "r");
    if (in == NULL) {
        printf("Ошибка открытия файла\n\n");
        return 0;
    }

    printf("Введите имя файла для сохранения\n");
    scanf("%s", new_fname);

    out = fopen(new_fname, "wt");
    if (in == NULL) {
        printf("Ошибка открытия файла\n\n");
        return 0;
    }
    
    while (fgets(line, sizeof(line), in) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        word_count = 0;
        char *word = strtok(line, " .,!?;:\t\n");
        
        while (word != NULL) {
            strcpy(words[word_count], word);
            word_count++;
            word = strtok(NULL, " .,!?;:\t\n");
        }

        for (int i = word_count - 1; i >= 0; i--) {
            fprintf(out, "%s ", words[i]);
        }
        fprintf(out, "\n");
    }

    fclose(out);
    fclose(in);

    return 0;
}