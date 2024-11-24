#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N  4 

sem_t mutex; 
int courant = 0; 

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;

    while (1) {
        sem_wait(&mutex);

        if (thread_id == courant) {
            printf("Thread %d s'exécute\n", thread_id + 1);
            current_thread = (current_thread + 1) % N;
        }

        sem_post(&mutex);
    }
}

int main() {
    pthread_t threads[N];
    int thread_ids[N];

    sem_init(&mutex, 0, 1);
      for (int i = 0; i < N; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }
    return 0;
}