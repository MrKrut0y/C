#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

typedef double (*TFun)(double);

double Y(double x);
double V(double x);
double S(double x);

void t_rez(TFun f, double a, double b, double h);
double calc_value(TFun f, double x);
void write_to_file(TFun f, double x);
double* calculate(TFun prtf, double *x, int n);
void print_array(double *arr, int n);

int main() {
    setlocale(LC_ALL, "Russian");

    double x, a, b, h;
    int choice1, choice2;

    TFun functions[] = {Y, V, S};
    const char* func_names[] = {"Y(x)", "V(x)", "S(x)"};

    while (1) {
        printf("\n---МЕНЮ---\n");
        printf("1) Вычислить значение\n");
        printf("2) Табулировать\n");
        printf("3) Выполнить операцию\n");
        printf("4) Выполнить операцию calculate\n");
        printf("5) Выход\n\n");

        scanf("%d", &choice1);

        if (choice1 == 5) {
            break;
        }
        
        if (choice1 < 1 || choice1 > 4) {
            printf("Неверный выбор!\n");
            continue;
        }

        printf("\nВыберите функцию:\n");
        printf("1) Y(x)\n");
        printf("2) V(x)\n");
        printf("3) S(x)\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice2);
        
        if (choice2 < 1 || choice2 > 3) {
            printf("Неверный выбор функции!\n");
            continue;
        }
        
        TFun f = functions[choice2 - 1];
        
        switch (choice1) {
            case 1: 
                printf("Введите x: ");
                scanf("%lf", &x);
                printf("%s при x = %.2f = %.4f\n", 
                       func_names[choice2 - 1], x, calc_value(f, x));
                break;
                
            case 2:
                printf("Введите a, b, h: ");
                scanf("%lf%lf%lf", &a, &b, &h);
                printf("\nТабуляция %s:\n", func_names[choice2 - 1]);
                t_rez(f, a, b, h);
                break;
                
            case 3:
                printf("Введите x: ");
                scanf("%lf", &x);
                write_to_file(f, x);
                printf("Значение записано в файл dat.txt\n");
                break;
                
            case 4:
                {
                    int n;
                    printf("Введите количество элементов массива x: ");
                    scanf("%d", &n);
                    
                    double *x_arr = (double*)malloc(n * sizeof(double));
                    if (x_arr == NULL) {
                        printf("Ошибка выделения памяти\n");
                        break;
                    }
                    
                    printf("Введите %d элементов массива x:\n", n);
                    for (int i = 0; i < n; i++) {
                        printf("x[%d] = ", i);
                        scanf("%lf", &x_arr[i]);
                    }
                    
                    double *result = calculate(f, x_arr, n);
                    
                    if (result != NULL) {
                        printf("\nРезультат работы calculate для функции %s:\n", 
                               func_names[choice2 - 1]);
                        printf("   i   |    x[i]    |   f(x[i])   |  2*f(x[i])\n");
                        printf("-------+------------+-------------+------------\n");
                        for (int i = 0; i < 20; i++) {
                            if (i < n) {
                                printf("%5d | %10.3f | %11.4f | %10.4f\n", 
                                       i, x_arr[i], f(x_arr[i]), result[i]);
                            } else {
                                printf("%5d | %10s | %11s | %10.4f\n", 
                                       i, "-", "-", result[i]);
                            }
                        }
                        
                        free(result);
                    }
                    
                    free(x_arr);
                }
                break;
        }
    }
    
    return 0;
}

double calc_value(TFun f, double x) {
    return f(x);
}

void write_to_file(TFun f, double x) {
    FILE *out = fopen("dat.txt", "a");
    if (out == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    fprintf(out, "x = %.4f, y = %.4f\n", x, f(x));
    fclose(out);
}

double* calculate(TFun prtf, double *x, int n) {
    double *result = (double*)malloc(20 * sizeof(double));
    if (result == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    
    for (int i = 0; i < 20 && i < n; i++) {
        result[i] = 2.0 * prtf(x[i]);
    }
    
    for (int i = n; i < 20; i++) {
        result[i] = 0.0;
    }
    
    return result;
}

void print_array(double *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%.4f", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

double Y(double x) {
    if (x <= 0) {
        printf("x должен быть > 0");
        return 0;
    }
    return log(fabs(sqrt(x * x * x)));
}

double V(double x) {
    if (x > 1) {
        double arg = x * x - 1;
        if (arg <= 0) {
            printf("аргумент tg <= 0 при x = %.2f\n", x);
            return 0;
        }
        return sqrt(tan(arg));
    }
    else if (x > 0 && x <= 1) {
        return -2 * x;
    }
    else if (x < 0) {
        return exp(cos(x));
    }
    else {
        printf("x = 0 не входит в область определения\n");
        return 0;
    }
}

double S(double x) {
    if (x == -1) {
        printf("x не входит в область определения\n");
        return 0;
    }
    
    double t = (x - 1) / (x + 1);
    double t3 = t * t * t;
    double t5 = t3 * t * t;
    double t7 = t5 * t * t;
    
    return t + (1.0/3.0) * t3 + (1.0/5.0) * t5 + (1.0/7.0) * t7;
}

void t_rez(TFun f, double a, double b, double h) {
    printf("\n    x     |    f(x)\n");
    printf("----------+----------\n");
    for (double x = a; x <= b + 1e-10; x += h) {
        printf("%10.3f | %10.3f\n", x, f(x));
    }
}