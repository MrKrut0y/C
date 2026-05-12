#include <stdio.h>
#include <locale.h>
#include "list.h"

int main() {

    setlocale(LC_ALL, "Russian");

    int H, K, L, M;

    printf("Enter the height[1-10]: ");
    scanf("%d", &H);
    if (H<1 || H >10) return 1;

    printf("Enter the number of stone bricks[0-10]: ");
    scanf("%d", &K);
    if (K<0 || K >10) return 1;

    printf("Enter the number of concrete bricks[0-10]: ");
    scanf("%d", &L);
    if (L<0 || L >10) return 1;

    printf("Enter the number of clay bricks[0-10]: ");
    scanf("%d", &M);
    if (M<0 || M >10) return 1;

    Brick* root = startWallBuilding(H, K, L, M);

    showBrickWall(root, H);

    root = startWallDestroying(root);

    showBrickWall(root, H);
    
    return 0;
}