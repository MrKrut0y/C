#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "list.h"

int main() {

    setlocale(LC_ALL, "Russian");

    char new_student[41];
    int M;

    if (scanf("%40s", new_student) != 1) {
        printf("no solution\n");
        return 0;
    }

    if (scanf("%d", &M) != 1) {
        printf("no solution\n");
        return 0;
    }

    if (M < 0 || M > 29) {
        printf("no solution\n");
        return 0;
    }

    char students[30][41];

    for (int i=0; i<30; i++) {
        students[i][0] = '\0';
    }

    for (int i=0; i<M; i++) {
        if (scanf("%40s", students[i]) != 1) {
            printf("no solution\n");
            return 0;
        }
    }

    if (M == 0) {
        printf("no solution\n");
        return 0;
    }

    for (int i=0; i<M-1; i++) {
        if (strcmp(students[i], students[i+1]) > 0) {
            printf("no solution\n");
            return 0;
        }
    }

    int index = searchString(students, M, new_student);

    if (index == -1) {
        strcpy(students[M], new_student);
        M++;
    } else {
        M = slideStringList(students, M, index);
        strcpy(students[index], new_student);
    }

    for (int i = 0; i < M; i++) {
        printf("%s\n", students[i]);
    }

    return 0;
}