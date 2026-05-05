#include <stdio.h>
#include "list.h"

int main() {
    
    List my_list;
    initlist(&my_list);

    insertfront(&my_list, 10);
    insertback(&my_list, 20);
    insertfront_str(&my_list, "qwrettry");

    printlist(my_list);

    printf("\nLength %d\n", length(my_list));

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}