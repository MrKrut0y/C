#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int m=1+rand()%10;

    int k; 
    scanf("%d", &k);

    if (k == m) {
        printf("right");
    } else {
        printf("not right");
    }

    return 0;
}