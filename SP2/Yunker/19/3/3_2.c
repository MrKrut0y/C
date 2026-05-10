#include <stdio.h>
#include <locale.h>

int recurs_func(char *str, int n) {

    if (n < 0) return 0;
    
    if (*str=='\0' || *str=='\n') return (n == 0);
    
    if (*str == '(') return recurs_func(str+1, n+1);

    else if (*str == ')') return recurs_func(str+1, n-1);

    else return recurs_func(str+1, n);

}

int main() {   // Задача "Проверка скобок"	

    setlocale(LC_ALL, "Russian");

    char str[101];

    fgets(str, 101, stdin);

    int result = recurs_func(str, 0);

    if (result) {
        printf("YES");
    } else {
        printf("NO");
    }

    

    return 0;
}