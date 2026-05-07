#include <stdio.h>
#include <locale.h>
#include "list.h"

int main() {

    setlocale(LC_ALL, "Russian");

    int size = 10;
    char** arr = init(size);
    
    print_arr(arr, size);

    int x;
    char str[100];
    printf("\nenter number line for change\n");
    scanf("%d", &x);
    printf("enter a different value\n");
    scanf("%s", &str);

    change_value(arr, x, str);

    printf("\n\n");

    print_arr(arr, size);

    free_arr(arr, size);

    return 0;
}