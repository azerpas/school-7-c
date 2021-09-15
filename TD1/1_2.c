#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>		//pour utiliser le rand() => "man 3 rand" pour accéder aux pages du manuel sinon c'est la commande rand
#include <time.h>		//pour utiliser le time()
#include <unistd.h>	
#include <semaphore.h>  //uniquement pour version avec semaphore

#define NB_THREADS 10

#define P(x) sem_wait(x)
#define V(x) sem_post(x)

sem_t sem;

void* handler(void *arg);
void* handler_barrier(void *arg);

int main(void) 
{
    pthread_t thread_ids[NB_THREADS+1];
    
    printf("Initiating sem");

    sem = sem_open("/sem", 0);

    printf("Initiated sem");

    // Create arg for each pthread
    int thread_args[NB_THREADS+1];

    for (size_t i = 0; i < NB_THREADS; i++)
    {
        thread_args[i] = i;
        pthread_create(&thread_ids[i], NULL, handler, &thread_args[i]);
        
    }
    pthread_create(NB_THREADS+1, NULL, handler_barrier, &thread_args[NB_THREADS+1]);
    
    for(size_t j=0; j < NB_THREADS; j++)
    {
        pthread_join(thread_ids[j], NULL);
    }
}

void* handler(void *arg)
{
    printf("Start...");
    usleep(10000);
    printf("Point atteint");
    V(&sem);
}

void* handler_barrier(void *arg)
{
    printf("Barrière atteinte, en attente...");
    for (size_t i = 0; i < NB_THREADS; i++)
    {
        P(&sem);
    }
    printf("Je peux continuer ! ");
}