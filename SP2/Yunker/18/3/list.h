#ifndef _LIST_H
#define _LIST_H

void free_arr(char** arr, int size);
void print_arr(char** arr, int size);
char** read_books_from_file1(const char *filename, int *count);
char** read_books_from_file2(const char *filename, int *count);
char** merge_arrays(char** arr1, int count1, char** arr2, int count2, int *total_count);
void find_and_print(char** arr, int size, const char *word);

#endif /* _LIST_H */