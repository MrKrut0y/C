#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

struct listitem {  
    int number; 
    char name[80]; 
    struct listitem *next;
};

typedef struct listitem *List;
typedef struct listitem Listitem;

void initlist(List *); /* инициализация списка пустым содержимым */
bool isempty (List *);/* проверяет, является ли список пустым*/
int length(List); /* определение длины списка */

void insertfront(List *, int val); /* вставка в список перед узлом со значением поля number=val */
void insertback(List *, int val); /* вставка в список перед узлом со значением поля number=val */

void insertfront_str(List *, char* str); /* вставка в список перед узлом со значением str в поле name */
void insertback_str(List *, char* str); /* вставка в список перед узлом со значением str в поле name */

void destroyItem(List *, List node); /* удаление заданного узла node из списка */
Listitem* getitem(List, int n); /* нахождение узла со значением n в поле number*/
Listitem* getitem_str(List, char* str); /* нахождение узла со значением str в поле name*/

void printlist(List);

#endif /* _LIST_H */
