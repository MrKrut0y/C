#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "list.h"
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    char str[100];
    printf("enter word\n");
    scanf("%s", str);
    printf("\n\n");

    char fname1[10] = "file1.txt";
    char fname2[10] = "file2.txt";

    int count1 = 0, count2 = 0, total_count = 0;

    char** arr1 = read_books_from_file1(fname1, &count1);

    char** arr2 = read_books_from_file2(fname2, &count2);

    char** all_books = merge_arrays(arr1, count1, arr2, count2, &total_count);

    //print_arr(arr, count);

    find_and_print(all_books, total_count, str);
        
    free_arr(all_books, total_count);
    free_arr(arr1, count1);
    free_arr(arr2, count2);

    //free_arr(author, count);

    return 0;
}