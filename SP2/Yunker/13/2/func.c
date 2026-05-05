#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "13.h"

int insert_student(char students[30][41], int *m, const char *new_student) {
    int count = *m;

    if (count == 0) {
        return -1;
    }
    
    for (int i=0; i<count-1;i++) {
        if (strcmp(students[i], students[i + 1]) >0) {
            return 0;
        }
    }

    int pos = count; 

    for (int i=0;i<count;i++) {
        if (strcmp(new_student, students[i]) < 0) {
            pos = i; 
            break;
        }
    }

    for (int i=count;i>pos;i--) {
        strcpy(students[i], students[i-1]);
    }

    strcpy(students[pos], new_student);
    (*m)++;

    return 1;
}