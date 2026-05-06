#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(queue_list *que) {
    while (!isempty_que(que)) {
        printf(FTYPE, deQueue(que));
    }
}

void init_que(queue_list *que) {
    que->end=que->begin= que->queue= NULL;
}

void init_st(stack *s) {
    s->top = -1;
}

int isfull_que(queue_list *que) {
    return 0;
}

int isfull_st(stack *s) {
    return s->top == NSTR - 1;
}

int isempty_que(queue_list *que) {
    return que->begin == NULL;
}

int isempty_st(stack *s) {
    return s->top == -1;
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

int push_st(stack *s, TYPE a) {

    if (isfull_st(s)) {
        printf("stack is full");
        return 0;
    }

    s->top++;
    s->data[s->top]=a;

    return 1;
}

TYPE pop_st(stack *s) {

    if (isempty_st(s)) {
        printf("stack is empty");
        return '\0';
    }

    TYPE a = s->data[s->top];
    s->top--;
    return a;
}

TYPE deQueue(queue_list *que) {
    if (isempty_que(que)) return 0;

    struct Node *temp = que->begin;
    TYPE value = temp->data;

    que->begin = que->begin->next;

    if (que->begin == NULL) {
        que->end = NULL;
    }

    free(temp);
    return value;
}

int is_palindrom(char *temp, int len) {

    queue_list que;
    stack s;

    init_que(&que);
    init_st(&s);

    for (int i=0; i<len; i++) {
        push_st(&s, temp[i]);
        enQueue(&que, temp[i]);
    }

    for (int i=0; i<len; i++) {
        TYPE st = pop_st(&s);
        TYPE qu = deQueue(&que);

        if (st != qu) {
            return 0;
        }
    }

    return 1;
    
    /*for (int i=0; i<len/2; i++) {
        if (temp[i] != temp[len-1-i]) {
            return 0;
        }
    }
    return 1;*/
}