#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initlist(List *lst) {
    *lst = NULL;
}

List create_node_int(int num) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode != NULL) {
        newNode->number = num;
        newNode->next = NULL;
    }
    return newNode;
}

void insertfront(List *lst, int num) {
    List newNode = create_node_int(num);
    if (newNode != NULL) {
        newNode->next = *lst;
        *lst = newNode;
    }
}

void printlist(List lst) {
    List current = lst;

    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
}

void destroyItem(List *lst, List node) {
    if (*lst == NULL || node == NULL) return;

    if (*lst == node) {
        *lst = node->next;
        free(node);
        return;
    }

    List prev = *lst;
    while (prev->next != NULL && prev->next != node) {
        prev = prev->next;
    }

    if (prev->next == node) {
        prev->next = node->next;
        free(node);
    }
}

Listitem* getitem(List lst, int num) {
    List current = lst;
    int count = 1;

    while (current != NULL && count < num) {
        current = current->next;
        count++;
    }
    return current;
}

int length(List lst) {
    int count = 0;
    while (lst != NULL) {
        count++;
        lst = lst->next;
    }
    return count;
}

void delete(List *lst) {
    if (*lst == NULL) {
        printf("empty\n");
        return;
    }

    int has_negative = 0;
    List current = *lst;

    while (current != NULL) {
        if (current->number < 0) {
            has_negative = 1;
            break;
        }
        current = current->next;
    }
    
    if (has_negative) {
        current = *lst;
        while (current != NULL) {
            List next_node = current->next;
            if (current->number < 0) {
                destroyItem(lst, current);
            }
            current = next_node;
        }
    } else {       
        List tenth = getitem(*lst, 10);
        if (tenth != NULL) {
            destroyItem(lst, tenth);
        }
    }
}
