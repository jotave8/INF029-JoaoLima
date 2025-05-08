#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define INCREMENTS_PER_THREAD 100000

volatile int shared_counter = 0;
pthread_mutex_t counter_mutex;

void* increment_counter_unsafe(void* arg){
	long thread_id = (long)arg;
	printf("Thread %ld iniciada (unsafe).\n", thread_id);

    for (int i = 0; i< INCREMENTS_PER_THREAD; i++){		
		//pthread_mutex_lock(&counter_mutex);
        shared_counter++;
        //pthread_mutex_unlock(&counter_mutex);
	}
    printf("Thread %ld finalizada (unsafe).\n", thread_id);
    return NULL;
}

int main(){
    pthread_t threads[NUM_THREADS];


    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, increment_counter_unsafe, (void*)(long)i);
    }

    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i],NULL);
    }

    printf("Valor final do contador: %d\n", shared_counter);
    return 0;
}