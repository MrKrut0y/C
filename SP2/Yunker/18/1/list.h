#ifndef _LIST_H
#define _LIST_H

char** init(int size);
void print_arr(char** arr, int size);
void free_arr(char** arr, int size);
void change_value(char** arr, int index, const char* new_value);

#endif /* _LIST_H */