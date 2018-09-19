#include <stdio.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define size 10

int count = 0;
int array[size];

int producer_is_alive = TRUE;
int consumer_is_alive = FALSE;

int produce_item() {
    return 0;
}

void push(int item) {
    if (count == size-1) {
        return;
    }
    count++;
    array[count] = item;
}

int pop() {
    if (count == 0) {
        return NULL;
    }
    int a = count;
    count--;
    return array[a];
}

void sleep_thread(int *status) {
    *status = FALSE;
    while (*status == FALSE) {
        if (status == &producer_is_alive) {
            printf("Count=: %d\tProducer sleeps\n", count);
        }
        if (status == &consumer_is_alive) {
            printf("Count=: %d\tConsumer sleeps\n", count);
        }
    }
}

void wakeup(int *status) {
    if (*status == FALSE) *status = TRUE;
}

void *producer(void) {
    int item;

    while (TRUE) {
        item = produce_item();
        if (count == size) sleep_thread(&producer_is_alive);
        push(item);

        printf("Inserted\n");

        if (count == 1) wakeup(&consumer_is_alive);
    }
}

void *consumer(void) {
    int item;
    while (TRUE) {
        if (count == 0) sleep_thread(&consumer_is_alive);
        item = pop();

        printf("Removed\n");

        if (count == size - 1) wakeup(&producer_is_alive);
    }
}


int main() {
    pthread_t consumer_th, producer_th;
    pthread_create(&consumer_th, NULL, consumer, NULL);
    pthread_create(&producer_th, NULL, producer, NULL);

    pthread_exit(NULL);
}