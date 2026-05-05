#include <stdio.h>
#include <locale.h>

#define MAX_SIZE 10


void squareInMatrix(int matr[MAX_SIZE][MAX_SIZE], int indexOfCornerH, int indexOfCornerW, int sizeOfSquare) {
    for (int i = 0; i < sizeOfSquare; i++) {
        for (int j = 0; j < sizeOfSquare; j++) {
            matr[indexOfCornerH + i][indexOfCornerW + j] = 1;
        }
    }
}

void printMatr(int matr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            printf("%2d", matr[i][j]);
        }
        printf("\n");
    }
}

void checkElement(int matr[MAX_SIZE][MAX_SIZE], int rows, int cols, int expected, const char* testName) {
    if (matr[rows][cols] != expected) {
        printf(" %s: Ошибка\n", testName);
        printf(" matr[%d][%d] = %d, ожидалось %d\n", rows, cols, matr[rows][cols], expected);
    } else {
        printf(" %s: OK (matr[%d][%d] = %d)\n", testName, rows, cols, matr[rows][cols]);
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    int matr[MAX_SIZE][MAX_SIZE] = {0};

    printMatr(matr, MAX_SIZE, MAX_SIZE);
    printf("\n");

    /*int indexOfCornerH;
    printf("x ");
    scanf("%d", &indexOfCornerH);
    printf("\n");

    int indexOfCornerW;
    printf("y ");
    scanf("%d", &indexOfCornerW);
    printf("\n");

    int sizeOfSquare;
    printf("Р Р°Р·РјРµСЂ ");
    scanf("%d", &sizeOfSquare);
    printf("\n");*/

    squareInMatrix(matr, 5, 5, 2);
    printMatr(matr, MAX_SIZE, MAX_SIZE);
    printf("\n");
    printf("\n");

    printf("\n2. Неверно рассчитывается правая граница квадрата (смещение на 1) \n");
    checkElement(matr, 5, 6, 1, "Тест 1, Правый верхний");
    checkElement(matr, 6, 6, 1, "Тест 1, Правый нижний");
    checkElement(matr, 6, 7, 0, "Тест 1, За правой границей (строка 6)");
    printf("\n");
    printf("\n");

    printf("3. Неверно рассчитывается нижняя граница квадрата (смещение на 1)\n");
    checkElement(matr, 7, 5, 0, "Тест 2, За нижней границей (столбец 5)");
    checkElement(matr, 7, 6, 0, "Тест 2, За нижней границей (столбец 6)");
    printf("\n");
    printf("\n");

    printf("4. Верхняя граница заполянется различными числами\n");
    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            matr[i][j] = 0;
    
    squareInMatrix(matr, 2, 2, 3);
    printMatr(matr, 7, 7);
    printf("\n");

    checkElement(matr, 2, 2, 1, "Тест 3, Верхняя граница [2][2]");
    checkElement(matr, 2, 3, 1, "Тест 3, Верхняя граница [2][3]");
    checkElement(matr, 2, 4, 1, "Тест 3, Верхняя граница [2][4]");

    int upper = 1;
    for (int j = 2; j < 5; j++) {
        if (matr[2][j] != 1) {
            upper = 0;
            break;
        }
    }

    if (upper) {
        printf("все элементы = 1\n");
    } else {
        printf("Ошибка\n");
    }
    printf("\n");
    printf("\n");

    printf("5. Запись элементов по диагонали вместо левой границы\n");
    checkElement(matr, 2, 2, 1, "Тест 4, Левая граница [2][2]");
    checkElement(matr, 3, 2, 1, "Тест 4, Левая граница [3][2]");
    checkElement(matr, 4, 2, 1, "Тест 4, Левая граница [4][2]");

    int left = 1;
    for (int i = 2; i < 5; i++) {
        if (matr[i][2] != 1) left = 0;
    }
    
    if (left) {
        printf("Все элементы = 1\n");
    } else {
        printf("Ошибка\n");
    }
    printf("\n");
    printf("\n");

    printf("6. Неверно учитывается размер квадрата (неверные границы цикла)\n");

    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            matr[i][j] = 0;
    
    squareInMatrix(matr, 1, 1, 4);
    
    printMatr(matr, 7, 7);
    printf("\n");

    int innerOK = 1;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            if (matr[i][j] != 1) {
                printf("Ошибка: matr[%d][%d] = %d\n", i, j, matr[i][j]);
                innerOK = 0;
            }
        }
    }
    if (innerOK) printf("Все внутренние элементы = 1\n");

    int border = 1;

    for (int i = 1; i < 5; i++) {
        if (matr[i][0] != 0) {
            printf("Ошибка: слева matr[%d][0] = %d\n", i, matr[i][0]);
            border = 0;
        }
    }

    for (int i = 1; i < 5; i++) {
        if (matr[i][5] != 0) {
            printf("Ошибка: справа matr[%d][5] = %d\n", i, matr[i][5]);
            border = 0;
        }
    }

    for (int j = 1; j < 5; j++) {
        if (matr[0][j] != 0) {
            printf("Ошибка: сверху matr[0][%d] = %d\n", j, matr[0][j]);
            border = 0;
        }
    }

    for (int j = 1; j < 5; j++) {
        if (matr[5][j] != 0) {
            printf("Ошибка: снизу matr[5][%d] = %d\n", j, matr[5][j]);
            border = 0;
        }
    }
    
    if (border) printf("Внешние границы не затронуты\n");
    
    if (innerOK && border) {
        printf("\nРазмер квадрата учтен правильно\n");
    } else {
        printf("\nОшибка в размере\n");
    }

    printf("7. Не учитывется размер квадарата = 1");
    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            matr[i][j] = 0;
    
    squareInMatrix(matr, 3, 3, 1);
    
    printf("Квадрат 1x1 с углом (3,3):\n");
    printMatr(matr, 7, 7);
    printf("\n");

    checkElement(matr, 3, 3, 1, "Единственный элемент");
    
    int neighborsOK = 1;
    int neighbors[8][2] = {
        {2, 2}, {2, 3}, {2, 4},
        {3, 2},        {3, 4},
        {4, 2}, {4, 3}, {4, 4}
    };
    
    for (int k = 0; k < 8; k++) {
        int i = neighbors[k][0];
        int j = neighbors[k][1];
        if (matr[i][j] != 0) {
            printf("  Ошибка: сосед matr[%d][%d] = %d (должно быть 0)\n", i, j, matr[i][j]);
            neighborsOK = 0;
        }
    }
    
    if (neighborsOK) {
        printf("Все соседние элементы = 0\n");
    }

    int oneChanged = 1;
    int countOnes = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (matr[i][j] == 1) countOnes++;
        }
    }
    
    if (countOnes == 1) {
        printf("Изменился ровно 1 элемент\n");
    } else {
        printf("Ошибка: изменилось %d элементов\n", countOnes);
        oneChanged = 0;
    }
    
    if (neighborsOK && oneChanged) {
        printf("\nРаботает корректно\n");
    } else {
        printf("\nОшибка\n");
    }

    return 0;
}
