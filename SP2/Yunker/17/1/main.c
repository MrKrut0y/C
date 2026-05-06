#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {

    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    int m = 1 + rand() % 3;

    printf("select: 1-stone, 2-paper, 3-scissors\n");

    int k; 
    scanf("%d", &k);

    if (k < 1 || k > 3) {
        printf("incorrect!\n");
        return 1;
    }

    if (k == 1 && m == 1) {
        printf("draw");
    } 

    else if ((k == 1 && m == 3) || 
        (k == 2 && m == 1) || 
        (k == 3 && m == 2) ) {
            printf("you win");
    } else {
        printf("you lose");
    }

    return 0;
}