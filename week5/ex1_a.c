#include <stdio.h>
#include <pthread.h>


void *print_text(void *vargp){
    int *myid = (int *)vargp;
    printf("Thread %d \n", *myid);
    fflush(stdout);
    pthread_exit(NULL);
    return NULL;
}

int main() {

    pthread_t thread_id;

    // Creating threads
    for(int i=0; i < 5; i++) {
        printf("START\n");
        fflush(stdout);
        pthread_create( &thread_id, NULL, print_text, (void *)&thread_id );
        //pthread_join(thread_id, NULL);
        printf("END\n");
        fflush(stdout);
    }

}