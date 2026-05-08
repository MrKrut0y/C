#ifndef _LIST_H
#define _LIST_H

char** init(int size);
void print_arr(char** arr, int size);
void free_arr(char** arr, int size);
int compare_str(const void *a, const void *b);

#endif /* _LIST_H */