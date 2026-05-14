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

Box* startFillingWarehouse(int NN, int N, int M);
void showWarehouse(Box* root, int M);
Box* startEmptyingWarehouse(Box* root);
int startBoxTransferring(Box** root, int target_id, int N, int M);
Box* findBox(Box* root, int id);
void popBox(Box* b, Box** root);
void pushBox(Box* b, Box* row_base);
Box* findBestRow(Box* root, Box* box_to_move, int M);

#endif /* _LIST_H */
