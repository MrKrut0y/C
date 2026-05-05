#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int x, k, x1, x2, x3, x4;


    printf("„исла x\n");
    scanf("%d", &x);

    while (25 <= x && x <= 0) {
        printf("„исло введено некорректно\n");
        printf("¬ведите число от 0 до 25\n");
        printf("„исло x\n");
        scanf("%d", &x);
    }
    
    printf("¬ведите 4 числа\n");
    scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
    printf("\n%d %d %d %d", (x1 + x)%26, (x2 + x)%26, (x3 + x)%26, (x4 + x)%26);

    return 0;
}