#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <locale.h>

#ifndef num_steps
#define num_steps 200000000
#endif

typedef struct {
    int thread_id;     // Номер потока
    int num_threads;   // Сколько всего потоков создано
} thread_data_t;

void* calculate_pi(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    
    double* partial_sum = malloc(sizeof(double));
    if (partial_sum == NULL) pthread_exit(NULL);
    
    *partial_sum = 0.0;

    for (int i = data->thread_id; i < num_steps; i += data->num_threads) {
        *partial_sum += 1.0 / (i * 4.0 + 1.0);
        *partial_sum -= 1.0 / (i * 4.0 + 3.0);
    }

    pthread_exit((void*)partial_sum);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    if (argc < 2) {
        printf("Использование: %s <количество_потоков>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n_threads = atoi(argv[1]);
    if (n_threads < 1) n_threads = 1;

    pthread_t threads[n_threads];
    thread_data_t params[n_threads];

    for (int i = 0; i < n_threads; i++) {
        params[i].thread_id = i;
        params[i].num_threads = n_threads;

        if (pthread_create(&threads[i], NULL, calculate_pi, &params[i]) != 0) {
            perror("Ошибка при создании потока");
            return EXIT_FAILURE;
        }
    }

    double total_pi = 0;

    for (int i = 0; i < n_threads; i++) {
        double* result;
        
        pthread_join(threads[i], (void**)&result);

        if (result != NULL) {
            total_pi += *result;
            free(result);
        }
    }

    total_pi *= 4.0;
    printf("Вычисленное значение PI: %.15g\n", total_pi);

    return EXIT_SUCCESS;
}