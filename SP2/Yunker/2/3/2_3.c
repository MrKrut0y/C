#include <stdio.h>
#include <locale.h>

void char_cesar(char *ch, int k) {

    k = k % 26;
    if (k < 0) {
        k += 26;
    }

    *ch = 'a' + (*ch - 'a' + k) % 26;
}

int main() {

    setlocale(LC_ALL, "Russian");

    char ch;
    int k;

    printf("¬ведите строчную латинскую букву: ");
    scanf(" %c", &ch);
    
    printf("¬ведите сдвиг: ");
    scanf("%d", &k);
    
    char_cesar(&ch, k);
    
    printf("%c\n", ch);

    return 0;
}