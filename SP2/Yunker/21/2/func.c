#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

Box* startFillingWarehouse(int NN, int N, int M) {

    if (NN < 1|| NN > 9999) return NULL;

    if (N < 1 || N > 10) return NULL;

    if (M < 1 || M > 10) return NULL;

    Box* root = NULL;
    Box* col_base = NULL;

    printf("Enter the boxes for each row (format: number,type, for example 0005,T). To complete the series, enter 0\n");

    for (int i=0;i<N;i++) {
        printf("Filling %d row:\n", i+1);

        Box* under = NULL;

        for (int j=0;j<M;j++) {
            int box_id;
            char box_type;

            if (scanf("%d", &box_id) != 1 || box_id == 0) {
                break;
            }

            scanf(",%c", &box_type);
            
            if (j == M - 1) {
                int extra_id;
                char extra_type;
                int has_overflow = 0;

                while (scanf("%d", &extra_id) == 1 && extra_id != 0) {
                    scanf(",%c", &extra_type);
                    has_overflow = 1;
                }

                if (has_overflow) {
                    printf("Warning: The row is full! Extra boxes are ignored.\n");
                }
            }

            Box* new_box = (Box*)malloc(sizeof(Box));
            new_box->id = box_id;
            new_box->type = box_type;
            new_box->up = NULL;
            new_box->down = NULL;
            new_box->right = NULL;
            new_box->left = NULL;

            if (root == NULL) {
                root = new_box;
                col_base = new_box;
                under = new_box;
                continue;
            }

            if (j == 0) {
                new_box->left = col_base;
                col_base->right = new_box;
                col_base = new_box;
            } else {
                new_box->down = under;
                under->up = new_box;
            

                if (under->left != NULL && under->left->up != NULL) {
                    Box* left_neighbor = under->left->up;
                    new_box->left = left_neighbor;
                    left_neighbor->right = new_box;
                }
            }   
            under = new_box;
        }
    }
    return root;
}

void showWarehouse(Box* root, int M) {

    if (root == NULL) {
        printf("no warehouse\n\n");
        return;
    }

    printf("\n\n");

    for (int h=M-1;h >= 0; h--) {
        Box* col_base = root;

        while (col_base != NULL)
        {
            Box* current = col_base;
            int current_h = 0;

            while (current != NULL && current_h < h) {
                current = current->up;
                current_h++;
            }

            if (current_h == h && current != NULL) {
                printf(" [%04d %c] ", current->id, current->type);
            } else {
                printf("           ");
            }

            col_base = col_base->right;
        }
        printf("\n");
    }
    printf("\n\n");
}

Box* startEmptyingWarehouse(Box* root) {

    if (root == NULL) {
        printf("The warehouse is already empty\n");
        return NULL;
    }

    Box* col_base = root;

    while (col_base->right != NULL) {
        col_base = col_base->right;
    }

    while (col_base != NULL) {

        Box* current = col_base;

        while (current->up != NULL) {
            current = current->up;
        }

        Box* next_col = col_base->left;

        while (current != NULL)
        {
            Box* del = current;
            current = current->down;
            free(del);
        }
        col_base = next_col;
    }
    printf("The warehouse is emptied\n");
    return NULL;
}

int startBoxTransferring(Box** root, int target_id, int N, int M) {
    Box* target = findBox(*root, target_id);
    if (!target) return 0;

    Box* top_in_col = target;
    while (top_in_col->up) top_in_col = top_in_col->up;

    if (top_in_col != target) {
        Box* best_row = findBestRow(*root, top_in_col, M);
        if (!best_row) return 0;

        Box* base = target;
        while (base->down) base = base->down;
        int base_id = base->id;

        popBox(top_in_col, root);
        pushBox(top_in_col, best_row);

        int res = startBoxTransferring(root, target_id, N, M);

        Box* original_col = findBox(*root, base_id);
        if (original_col) {
            while (original_col->down) original_col = original_col->down;
            popBox(top_in_col, root);
            pushBox(top_in_col, original_col);
        }
        return res;
    } else {
        popBox(target, root);
        free(target);
        return 1;
    }
}

Box* findBox(Box* root, int id) {
    Box* col = root;
    while (col) {
        Box* curr = col;
        while (curr) {
            if (curr->id == id) return curr;
            curr = curr->up;
        }
        col = col->right;
    }
    return NULL;
}

void popBox(Box* b, Box** root) {
    if (!b) return;

    if (b->up) b->up->down = b->down;
    if (b->down) b->down->up = b->up;

    if (b->left) b->left->right = b->right;
    if (b->right) b->right->left = b->left;

    if (b == *root) {
        if (b->up) {
            *root = b->up;
            if (b->right) { b->up->right = b->right; b->right->left = b->up; }
        } else {
            *root = b->right;
        }
    }

    b->up = b->down = b->left = b->right = NULL;
}

void pushBox(Box* b, Box* row_base) {
    if (!b || !row_base) return;

    Box* top = row_base;
    while (top->up) top = top->up;

    top->up = b;
    b->down = top;

    if (top->left && top->left->up) {
        b->left = top->left->up;
        top->left->up->right = b;
    }
    if (top->right && top->right->up) {
        b->right = top->right->up;
        top->right->up->left = b;
    }
}

Box* findBestRow(Box* root, Box* to_move, int M) {
    Box* col = root;
    while (col) {
        Box* temp = to_move;
        while (temp->down) temp = temp->down;
        if (temp == col) { col = col->right; continue; }

        int h = 0;
        Box* curr = col;
        while (curr) { h++; curr = curr->up; }

        if (h < M && col->type == to_move->type) return col;
        
        col = col->right;
    }
    return NULL;
}