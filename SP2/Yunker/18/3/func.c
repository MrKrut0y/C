#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_arr(char** arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%s\n", arr[i]);
    }
}

void free_arr(char** arr, int size) {
    for (int i=0; i<size; i++) {
        free(arr[i]);
    }
    free(arr);
}

char** read_books_from_file1(const char *filename, int *count) {
    
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        printf("file opening error %s\n", filename);
        *count = 0;
        return NULL;
    }

    char **str = NULL;
    char buffer[256];
    int size = 0;
    int capacity = 10;

    str = (char**)malloc(capacity * sizeof(char*));
    if (str == NULL) {
        printf("error malloc\n");
        fclose(file);
        *count = 0;
        return NULL;
    }

    int line_num = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        line_num++;
        
        buffer[strcspn(buffer, "\n")] = 0;
        
        if (strlen(buffer) == 0) {
            continue;
        }
        
        char *open_quote = strchr(buffer, '"');
        char *close_quote = strrchr(buffer, '"');
        
        if (open_quote && close_quote && open_quote != close_quote) {
            int title_len = close_quote - open_quote - 1;
            
            char title[200];
            strncpy(title, open_quote + 1, title_len);
            title[title_len] = '\0';
            
            str[size] = (char*)malloc((strlen(title) + 1) * sizeof(char));
            if (str[size] == NULL) {
                printf("error malloc \n");
                break;
            }
            strcpy(str[size], title);
            size++;
        }
        
        if (size >= capacity) {
            capacity *= 2;
            str = (char**)realloc(str, capacity * sizeof(char*));
        }
    }
    
    *count = size;
    fclose(file);
    return str;
}

void find_and_print(char** arr, int size, const char *word) {
    int found = 0;
    
    for (int i=0; i<size; i++) {
        if (strstr(arr[i], word) != NULL) {
            printf("%d. %s\n", ++found, arr[i]);
        }
    }
    
    if (found == 0) {
        printf("not found\n");
    }
}

char** read_books_from_file2(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("error opening file %s\n", filename);
        *count = 0;
        return NULL;
    }

    char **titles = NULL;
    char buffer[5000];
    int size = 0;
    int capacity = 50;

    titles = (char**)malloc(capacity * sizeof(char*));
    if (!titles) {
        fclose(file);
        *count = 0;
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        if (strlen(buffer) == 0) continue;
        
        char *ptr = buffer;
        char *start = ptr;
        
        while (*ptr != '\0') {
            if (strncmp(ptr, " / ", 3) == 0) {
                if (ptr > start) {
                    char temp[500];
                    int len = ptr - start;
                    strncpy(temp, start, len);
                    temp[len] = '\0';
                    
                    if (strlen(temp) > 3) {
                        titles[size] = (char*)malloc(strlen(temp) + 1);
                        strcpy(titles[size], temp);
                        size++;
                    }
                }
                ptr += 3;
                start = ptr;
            } else {
                ptr++;
            }
        }

        if (ptr > start) {
            char temp[500];
            int len = ptr - start;
            strncpy(temp, start, len);
            temp[len] = '\0';
            if (strlen(temp) > 3) {
                titles[size] = (char*)malloc(strlen(temp) + 1);
                strcpy(titles[size], temp);
                size++;
            }
        }
        
        if (size >= capacity) {
            capacity *= 2;
            titles = (char**)realloc(titles, capacity * sizeof(char*));
        }
    }
    
    *count = size;
    fclose(file);
    return titles;
}

char** merge_arrays(char** arr1, int count1, char** arr2, int count2, int *total_count) {
    *total_count = count1 + count2;
    
    char** merged = (char**)malloc((*total_count) * sizeof(char*));
    if (!merged) return NULL;
    
    for (int i = 0; i < count1; i++) {
        merged[i] = (char*)malloc(strlen(arr1[i]) + 1);
        strcpy(merged[i], arr1[i]);
    }
    
    for (int i = 0; i < count2; i++) {
        merged[count1 + i] = (char*)malloc(strlen(arr2[i]) + 1);
        strcpy(merged[count1 + i], arr2[i]);
    }
    
    return merged;
}