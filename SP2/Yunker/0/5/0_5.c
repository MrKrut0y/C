#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int sum = 0;
    int x = 0;
    int zero = 0;
    int b = 0;

    printf("¬ведите последовательность целых чисел\n");

    while (1) {
        scanf("%d", &x);

        if (x == -9999) {
            break;
        }

        if (zero<2) {
            if (x==0) {
                zero++;
                if (zero == 1) {
                    b = 1;
                } 
                else if (zero == 2) {
                    b = 0;
                }
            }
            else if (b==1) {
                sum += x;
            }
        }

    }
    
    if (zero < 2) {
        printf("должно быть два нул€!\n");
        return 1;
    }

    printf("—умма %d", sum);

    return 0;
}