#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(stack *s) {
    int i = s->top;
    while (i>=0)
    printf(FTYPE, s->data[i--]);
}

int push(stack *s, TYPE a) {
    
    if (isfull(s)) {
        printf("стек переполнен\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = a;

    return 1;
}

int isfull(stack *s) {
    return s->top == NMAX - 1;
}


int isempty(stack *s) {
    return s->top == -1;
}

TYPE pop(stack *s) {
    if (isempty(s)) {
        printf("стек пуст");
        return '\0';
    }
    TYPE a = s->data[s->top];
    s->top--;
    return a;
}

TYPE top(stack *s) {
    if (isempty(s)) {
        printf("стек пуст\n");
        return '\0';
    }
    return s->data[s->top];
}
