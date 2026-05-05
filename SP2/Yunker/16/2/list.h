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

int isempty(queue_list *que);// ���������, ���� ���� ���� {top==0} ������� 1, ����� 0
int isfull(queue_list *que);// ���������, ���� ���� ����� {top==NMAX-1} ������� 1, ����� 0

void display(queue_list *que);

#endif /* _LIST_H */