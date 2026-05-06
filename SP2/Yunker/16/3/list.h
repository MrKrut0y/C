#ifndef _LIST_H
#define _LIST_H

#define NSTR 1000
#define TYPE char
#define FTYPE "%3c,"

struct Node {
    TYPE data;
    struct Node *next;
};

typedef struct {
    struct Node *queue;
    struct Node *begin;
    struct Node *end;
} queue_list;

void enQueue(queue_list *que, TYPE element); //добавить элемент в очередь
TYPE deQueue(queue_list *que); //извлечь элемент из очереди

int isempty_que(queue_list *que);// ���������, ���� ���� ���� {top==0} ������� 1, ����� 0
int isfull_que(queue_list *que);// ���������, ���� ���� ����� {top==NMAX-1} ������� 1, ����� 0
void init_que(queue_list *que);

void display(queue_list *que);
int is_palindrom(char *temp, int len);

typedef struct  Stack {
    int   top;
    TYPE  data[NSTR];
} stack;

void init_st(stack *s);
int isempty_st(stack *s);// проверить, если стек пуст {top==0} вернуть 1, иначе 0
int isfull_st(stack *s);// проверить, если стек полон {top==NMAX-1} вернуть 1, иначе 0
int push_st(stack *s, TYPE a);//поместить элемент а в стек  {top=top+1, data[top]=a}, если стек не полон
TYPE pop_st(stack *s);


#endif /* _LIST_H */