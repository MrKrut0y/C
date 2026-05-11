#ifndef _LIST_H
#define _LIST_H

typedef struct Brick {
    int id;
    char material;
    struct Brick* up;
    struct Brick* down;
    struct Brick* left;
    struct Brick* right;
} Brick;

#endif /* _LIST_H */