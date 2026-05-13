#ifndef _LIST_H
#define _LIST_H

typedef struct Box {
    int id;
    char type;
    struct Box* up;
    struct Box* down;
    struct Box* left;
    struct Box* right;
} Box;

Box* startEmptyingWarehouse(Box* root);
void showWarehouse(Box* root, int M);
Box* startFillingWarehouse(int NN, int N, int M);
Box* startBoxTransferring(Box* root, int NN, int N, int M);
void popBox(Box* b);

#endif /* _LIST_H */
