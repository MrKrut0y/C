#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>


int main() {
    setlocale(LC_ALL, "Russian");

    struct tm *mytime;
    time_t t;
    char time_str[100];
    char centered_str[80 + 1];
    int i;

    t = time(NULL);
    mytime = localtime(&t);

    sprintf(time_str, "Moscow time %02d:%02d:%02d", 
            mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    int text_len = strlen(time_str);
    int padding = (80 - text_len) / 2;

    sprintf(centered_str, "%*s%s%*s", padding, "", time_str, 
            80 - text_len - padding, "");

    printf("********************************************************************************\n");

    printf("*");
    for (i = 0; i < 80 - 2; i++) printf(" ");
    printf("*\n");

    printf("*");
    for (i = 0; i < 80 - 2; i++) {
        if (i < padding - 1) {
            printf("*");
        } else if (i >= padding - 1 && i < padding - 1 + text_len) {
            printf("%c", time_str[i - (padding - 1)]);
        } else {
            printf("*");
        }
    }
    printf("*\n");

    printf("*");
    for (i = 0; i < 80 - 2; i++) printf(" ");
    printf("*\n");

    printf("********************************************************************************\n");
    
    return 0;
}