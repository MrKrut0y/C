#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

struct listitem
{
    int number; 
    struct listitem *next;
};

typedef struct listitem *List;
typedef struct listitem Listitem;

void initlist(List *); /* инициализация списка пустым содержимым */
void insertfront(List *, int val); /* вставка в список перед узлом со значением поля number=val */
void destroyItem(List *, Listitem *); /* удаление заданного узла node из списка */
Listitem* getitem(List, int n); /* нахождение узла со значением n в поле number*/
int length(List);
void delete(List *);

void printlist(List);

#endif /* _LIST_H */
