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
int startBoxTransferring(Box** root, int NN, int N, int M);
void popBox(Box* top_box);
void pushBox(Box* box_to_push, Box* row_base);
Box* findBestRow(Box* root, Box* box_to_move, int M);
Box* findBox(Box* root, int NN);

#endif /* _LIST_H */
