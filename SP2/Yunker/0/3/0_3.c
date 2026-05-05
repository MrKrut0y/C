#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int x1, x2, x3, x4;
    printf("Введите IP адрес\n");
    if(scanf("%d.%d.%d.%d",&x1,&x2,&x3,&x4)==4 && x1>=0&&x1<=255&&x2>=0&&x2<=255&&x3>=0&&x3<=255&&x4>=0&&x4<=255)
        printf("Валиден\n");
    else
        printf("Невалиден\n");
    printf("%d.%d.%d.%d", x1, x2, x3, x4);

    return 0;
}