#include <stdio.h>
#include <string.h>
#include "list.h"

int searchString(const char stringList[30][41], int count, const char str[41]) {
    for (int i=0; i<count; i++) {
        if (strcmp(stringList[i], str) >= 0) {
            return i;
        }
    }
    return -1;
}

int slideStringList(char stringList[30][41], int count, int strIndex) {
    for (int i = count; i > strIndex; i--) {
        strcpy(stringList[i], stringList[i - 1]);
    }
    stringList[strIndex][0] = '\0';
    
    return count + 1;
}