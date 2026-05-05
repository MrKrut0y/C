#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(queue_list *que) {
    while (!isempty(que)) {
        printf(FTYPE, deQueue(que));
    }
}

int isfull(queue_list *que) {
    return 0;
}

int isempty(queue_list *que) {
    return que->begin == NULL;
}

void enQueue(queue_list *que, TYPE temp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = temp;
    newNode->next = NULL;

    if (que->end == NULL) {
        que->begin = que->end = newNode;
        return;
    }
    
    que->end->next = newNode;
    que->end = newNode;
}

TYPE deQueue(queue_list *que) {
    if (isempty(que)) return 0;

    struct Node *temp = que->begin;
    TYPE value = temp->data;

    que->begin = que->begin->next;

    if (que->begin == NULL) {
        que->end = NULL;
    }

    free(temp);
    return value;
}