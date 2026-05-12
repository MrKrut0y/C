#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

Brick* startWallBuilding(int H, int K, int L, int M) {

    if (H<1 || H>10) return NULL;

    if ((K<0 || K>10) || (L<0 || L>10) || (M<0 || M>10)) return NULL;

    int total = K + L + M;

    if (total == 0) return NULL;
    Brick* root = NULL;
    Brick* col_base = NULL;
    
    int current_id = 1;

    while (current_id <= total) {
        
        Brick* under = NULL;
        
        for (int h = 0; h < H && current_id <= total; h++) {

            Brick* new_brick = (Brick*)malloc(sizeof(Brick));
            new_brick->id = current_id++;

            if (K > 0) { new_brick->material = 'S'; K--; }
            else if (L > 0) { new_brick->material = 'C'; L--; }
            else { new_brick->material = 'L'; M--; }

            new_brick->up = NULL;
            new_brick->down = NULL;
            new_brick->left = NULL;
            new_brick->right = NULL;

            if (root == NULL) {
                root = new_brick;
                col_base = new_brick;
                under = new_brick;
                continue;
            }

            if (h == 0) {
                new_brick->left = col_base;
                col_base->right = new_brick;
                col_base = new_brick;
                under = new_brick;
            } else {
                new_brick->down = under;
                under->up = new_brick;

                if (under->left != NULL && under->left->up != NULL) {
                    Brick* left_neighbor = under->left->up;
                    new_brick->left = left_neighbor;
                    left_neighbor->right = new_brick;
                }
                under = new_brick;
            }
        }
    }
    return root;
}

Brick* startWallDestroying(Brick* root) {

    if (root == NULL) return NULL;

    Brick* col_base = root;

    while (col_base->right != NULL) col_base = col_base->right;

    while (col_base != NULL) {
        Brick* current = col_base;

        while (current->up != NULL) current = current->up;

        Brick* next_col = col_base->left;

        while (current != NULL) {
            Brick* del = current;
            current = current->down;
            free(del);
        }

        col_base = next_col;
    }

    printf("The wall is destroyed\n");
    return NULL;
}

void showBrickWall(Brick* root, int H) {

    if (root == NULL) {
        printf("no wall");
        return;
    }

    for (int h = H-1; h >= 0; h--) {
        Brick* col_base = root; 

        while (col_base != NULL) {
            Brick* current = col_base;

            int current_h = 0;

            while (current != NULL && current_h < h) {
                current = current->up;
                current_h++;
            }

            if (current_h == h && current != NULL) {
                printf(" [%02d,%c] ", current->id, current->material);
            } else {
                printf("       ");
            }

            col_base = col_base->right;
        }
        printf("\n");
    }

    printf("\n\n");
}