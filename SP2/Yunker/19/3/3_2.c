#include <stdio.h>
#include <locale.h>

int recurs_func(char n) {

    if (n==NULL) return 0;

    

    return ;
}

int main() {   // Задача "Проверка скобок"	

    setlocale(LC_ALL, "Russian");

    char str[101];

    fgets(str, 101, stdin);

    int result = recurs_func(str);

    if (result) {
        printf("YES");
    } else {
        printf("NO");
    }

    

    return 0;
}