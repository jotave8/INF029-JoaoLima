#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define INCREMENTS_PER_THREAD 100000

volatile int shared_counter = 0; //declara o como volatile pra mostrar que o valor pode mudar inesperadamente por conta de outra thread
pthread_mutex_t counter_mutex; //seria utilizado para anular a condição de corrida e garantir que o recurso seja utilizado por apenas uma thread de cada vez

void* increment_counter_unsafe(void* arg){
	long thread_id = (long)arg; //converte o argumento para inteiro
	printf("Thread %ld iniciada (unsafe).\n", thread_id);

    for (int i = 0; i< INCREMENTS_PER_THREAD; i++){		
        shared_counter++; //incrementa o contador (com a condição de corrida, a variável pode ser manipulada ao mesmo tempo por várias threads)
	}
    printf("Thread %ld finalizada (unsafe).\n", thread_id);
    return NULL;
}

int main(){
    pthread_t threads[NUM_THREADS];


    for (int i = 0; i < NUM_THREADS; i++){ //cria as threads
        pthread_create(&threads[i], NULL, increment_counter_unsafe, (void*)(long)i); //função da biblioteca pthread que armazena o ID da thread, informa a função que será executada e passsa o ID da thread como argumento para a função
    }

    for (int i = 0; i < NUM_THREADS; i++){ //espera todas as threads serem finalizadas
        pthread_join(threads[i],NULL); //função que evita que o programa termine antes das threads concluírem recebendo o ID da thread como parametro
    }

    printf("Valor final do contador: %d\n", shared_counter); //com a condição de corrida, o valor do contador nunca será 500000 (pode chegar perto)
    return 0;
}