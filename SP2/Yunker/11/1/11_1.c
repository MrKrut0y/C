#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*TFun) (double);

double Y(double x);
double V(double x);
double S(double x);

void t_rez(TFun f, double a, double b, double h, const char* func_name);

int main() {

    setlocale(LC_ALL, "Russian");

    double a, b, h;
    int choice;

    printf("Доступные функции:\n");
    printf("1) Y(x) = ln|?(x?)|, при x > 0\n");
    printf("2) V(x) = { ?tg(x?-1), x>1; -2x, 0<x?1; e^cos(x), x<0 }\n");
    printf("3) S(x) = (x-1)/(x+1) + 1/3·((x-1)/(x+1))? + 1/5·((x-1)/(x+1))? + 1/7·((x-1)/(x+1))?\n\n");
    scanf("%d", &choice);

    puts("Input a,b,h");
    scanf("%lf%lf%lf", &a, &b, &h);

    switch(choice) {
        case 1:
            t_rez(Y, a, b, h, "Y(x)");
            break;
        case 2:
            t_rez(V, a, b, h, "V(x)");
            break;
        case 3:
            t_rez(S, a, b, h, "S(x)");
            break;
        default:
            printf("Неверный выбор\n");
            return 1;
    }

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

void t_rez(TFun f, double a, double b, double h, const char* func_name) {
    for (double x = a; x <= b; x += h) {
        printf("%10.3f | %10.3f\n", x, f(x));
    }
}
