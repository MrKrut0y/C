#include <stdio.h>
#include <locale.h>
#include <pthread.h>
#include <unistd.h>

void cleanup_handler(void *arg) {
    printf("Дочерняя нить: выполняется обработчик очистки\n");
    printf("Дочерняя нить: завершаю работу\n");
}

void* thread_print(void *arg) {
    pthread_cleanup_push(cleanup_handler, NULL);

    int count = 0;
    while(1) {
        count++;
        printf("Дочерняя нить: сообщение %d\n", count);
        sleep(1);
    }

    pthread_cleanup_pop(1);
    return NULL;
}

int main() {
    //setlocale(LC_ALL, "");

    pthread_t thread;

    if (pthread_create(&thread, NULL, thread_print, NULL) != 0) {
        return 1;
    }

    printf("Родитель: жду 2 секунды\n");
    sleep(2);

    printf("Родитель: выполняю pthread_cancel!\n");
    pthread_cancel(thread);

    pthread_join(thread, NULL);
    printf("Родитель: дочерняя нить успешно завершена\n");

    return 0;
}
