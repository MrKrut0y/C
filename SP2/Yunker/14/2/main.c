#include <stdio.h>
#include <time.h>
#include "list.h"
#include <stdlib.h>

#define N 23

int main() {         // 7 
    
    srand(time(NULL));
    
    List my_list;
    initlist(&my_list);

    for (int i=0; i<N; i++) {
        int x = rand() % 199 - 99; // -99 99
        insertfront(&my_list, x);
    }
    
    printf("before\n\n");
    printlist(my_list);

    delete(&my_list);
    
    printf("\n\nafter\n\n");
    printlist(my_list);

    while (my_list != NULL) {
        destroyItem(&my_list, my_list);
    }

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}