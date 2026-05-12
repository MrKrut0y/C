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

void showBrickWall(Brick* root, int H);
Brick* startWallDestroying(Brick* root);
Brick* startWallBuilding(int H, int K, int L, int M);

#endif /* _LIST_H */