#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {

    setlocale(LC_ALL, "Russian");   // 7

    char fname[20];
    char new_fname[20];
    char name[100];
    char ext[20];
    int n = 1;
    int new =0;
    int a;

    FILE* in;
    puts("Укажите файл для чтения(input.txt)");
    scanf("%s", fname);
    in = fopen(fname, "rt"); 
    if (in == NULL) {
        printf("Ошибка открытия");
        return 0;
    }

    char *dot = strrchr(fname, '.');
    if (dot != NULL) {
        int name_len = dot - fname;
        strncpy(name, fname, name_len);
        name[name_len] = '\0';
        strcpy(ext, dot);
        sprintf(new_fname, "%s_result%s", name, ext);
    }

    FILE *out;
    if ((out = fopen(new_fname, "wt")) == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    printf("Содержимое нового файла %s\n", new_fname);
    while (fscanf(in, "%d", &a) == 1) {
        new = n+a;
        printf("%d\n", new);
        fprintf(out, "%d\n", new);
        n++;
    }
    
    fclose(out);
    fclose(in);

    return 0;
}
