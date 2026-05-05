#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*TFun) (double);

double Y(double x);
double V(double x);
double S(double x);

void t_rez(TFun f, double a, double b, double h);
double calc_value(TFun f, double x);
void write_to_file(TFun f, double x);

int main() {                                // 1

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
        printf("4) Выход\n\n");

        scanf("%d", &choice1);

        if (choice1 == 4) {
            printf("Выход из программы\n");
            break;
        }
        
        if (choice1 < 1 || choice1 > 3) {
            printf("Неверный выбор!\n");
            continue;
        }

        printf("\nВыберите функцию:\n");
        printf("1) Y(x) = ln|?(x?)|\n");
        printf("2) V(x) = кусочная функция\n");
        printf("3) S(x) = ряд\n");
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

double Y(double x) {
    if (x<=0) {
        printf("x должен быть > 0");
        return 0;
    }
    return log(fabs(sqrt(x*x*x)));
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
    for (double x = a; x <= b; x += h) {
        printf("%10.3f | %10.3f\n", x, f(x));
    }
}
