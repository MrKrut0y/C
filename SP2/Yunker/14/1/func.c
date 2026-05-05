#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List create_node_int(int num) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode != NULL) {
        newNode->number = num;
        newNode->name[0] = '\0';
        newNode->next = NULL;
    }
    return newNode;
}

List create_node_str(char *str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode != NULL) {
        newNode->number = -1;
        strncpy(newNode->name, str, 79);
        newNode->name[79] = '\0';
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

void insertfront_str(List *lst, char *str) {
    List newNode = create_node_str(str);
    if (newNode != NULL) {
        newNode->next = *lst;
        *lst = newNode;
    }
}

void insertback(List *lst, int num) {
    List newNode = create_node_int(num);
    if (newNode == NULL) return;

    if (isempty(lst) == true) {
        *lst = newNode;
    } else {
        List current = *lst;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }   
}

void insertback_str(List *lst, char *str) {
    List newNode = create_node_str(str);
    if (newNode == NULL) return;

    if (isempty(lst) == true) {
        *lst = newNode;
    } else {
        List current = *lst;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }   
}

bool isempty(List *lst) {
    if (*lst == NULL) {
        return true;
    } else {
        return false;
    }
}

int length(List lst) {
    int count = 0;
    while (lst != NULL) {
        count++;
        lst = lst->next;
    }
    return count;
}

Listitem* getitem(List lst, int num) {
    List current = lst;

    while (current != NULL) {
        if (current->number == num) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Listitem* getitem_str(List lst, char *str) {
    List current = lst;

    while (current != NULL) {
        // strcmp возвращает 0, если строки полностью идентичны
        if (strcmp(current->name, str) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void destroyItem(List *lst, List node) {
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

void printlist(List lst) {
    List current = lst;

    while (current != NULL) {
        printf("%d %s\n", current->number, current->name);
        current = current->next;
    }
}