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

int startBoxTransferring(Box** root, int NN, int N, int M) {

    Box* target = findBox(*root, NN);

    if (target == NULL) {
        printf("no solution\n");
        return 0;
    }

    Box* top_box = target;
    while (top_box->up != NULL) {
        top_box = top_box->up;
    }

    if (top_box != target) {

        Box* best_row = findBestRow(*root, top_box, M);

        if (best_row == NULL) {
            return 0;
        }

        Box* original_row_base = target;
        while (original_row_base->down != NULL) {
            original_row_base = original_row_base->down;
        }

        popBox(top_box);
        pushBox(top_box, best_row);

        int result = startBoxTransferring(root, NN, N, M);

        popBox(top_box);
        pushBox(top_box, original_row_base);

        if (result == 0) {
            return 0;
        }
        
        return 1;

    } else {
        popBox(top_box);

        if (top_box->left != NULL) {
            top_box->left->right = top_box->right;
        }

        if (top_box->right != NULL) {
            top_box->right->left = top_box->left;
        }

        if (top_box == *root) {
            *root = top_box->right;
            if (*root != NULL) {
                (*root)->left = NULL;
            }
        }

        free(top_box);
        printf("Box %04d extracted successfully\n", NN);
    }
    
    return 1;
}

Box* findBox(Box* root, int NN) {

    Box* col_base = root;

    while (col_base != NULL) {
        Box* current = col_base;
        
        while (current != NULL) {
            if (current->id == NN) {
                return current;
            }
            current = current->up;
        }
        col_base = col_base->right;
    }
    return NULL;
}

void popBox(Box* top_box) {

    if (top_box == NULL) return;

    if (top_box->down != NULL) {
        top_box->down->up = NULL;
    }

    top_box->down = NULL;
    top_box->up = NULL;  
    top_box->left = NULL;
    top_box->right = NULL;
}

void pushBox(Box* box_to_push, Box* row_base) {

    if (box_to_push == NULL || row_base == NULL) return;

    Box* current = row_base;

    while (current->up != NULL) {
        current = current->up;
    }

    current->up = box_to_push;
    box_to_push->down = current;
    box_to_push->up = NULL;

    if (current->left != NULL && current->left->up != NULL) {
        box_to_push->left = current->left->up;
        current->left->up->right = box_to_push;
    }
    if (current->right != NULL && current->right->up != NULL) {
        box_to_push->right = current->right->up;
        current->right->up->left = box_to_push;
    }
}

Box* findBestRow(Box* root, Box* box_to_move, int M) {

    Box* col_base = root;

    while (col_base != NULL) {


        Box* check_own = col_base;
        int is_own_row = 0;
        while (check_own != NULL) {
            if (check_own == box_to_move) {
                is_own_row = 1;
                break;
            }
            check_own = check_own->up;
        }

        if (is_own_row) {
            col_base = col_base->right;
            continue;
        }

        Box* current = col_base;
        int height = 0;
        char row_type = col_base->type;

        while (current != NULL) {
            height++;
            current = current->up;
        }

        if (height < M && row_type == box_to_move->type) {
            return col_base;
        }
        col_base = col_base->right;
    }
    return NULL;
}