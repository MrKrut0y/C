#include <stdio.h>
#include <locale.h>
#include <time.h>

int main() {

    setlocale(LC_ALL, "Russian");

    struct tm *mytime;
    time_t t;
    t = time(NULL);
    mytime= localtime(&t);
    printf("Moscow time %02d:%02d:%02d \n", mytime ->tm_hour, mytime ->tm_min, mytime ->tm_sec);


    return 0;
}
