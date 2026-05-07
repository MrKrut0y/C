#ifndef _LIST_H
#define _LIST_H

int rand10_(int mmax); // целое число от 1 до mmax
int* rand10(int n, int mmax); // n целых чисел от 1 до mmax
double* rand_double_(int n, double dm);//n вещественных чисел в диапазоне от -dm до +dm
double rand_double(double dmin, double dmax); //вещественное число в заданном диапазоне
void print_int_arr(int* arr, int n);
void print_double_arr(double* arr, int n);

void build_histogram(int* counter, int height, int k);

#endif /* _LIST_H */