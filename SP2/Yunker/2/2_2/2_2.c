#include <stdio.h>
#include <locale.h>
#include <ctype.h>

void char_register(char *ch, int fl) {
    
    if (fl == 1) {
        *ch = toupper(*ch);
    }
    else {
        *ch = tolower(*ch);
    }
   

}

int main() {

    setlocale(LC_ALL, "Russian");

    char ch;
    int fl = 1;

    printf("Введите символ \n");
    scanf("%c", &ch);

    printf("Введите число \n");
    scanf("%d", &fl);

    char_register(&ch, fl);

    printf("%c", ch);

    return 0;
}
