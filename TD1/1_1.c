#include <stdlib.h> 
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define P sem_wait
#define V sem_post
#define NUMBER_OF_THREADS 2

sem_t sem;

struct thread_info {
    pthread_t thread_id;
    int       thread_num;
};

handler1(){
    printf("je");
    P(&sem);
    printf("mes");
    V(&sem);
}

handler2(){
    P(&sem);
    printf("synchronise");
    V(&sem);
    printf("threads");
}

int main(){
    pthread_attr_t attr;
    void *res;
    int s;

    sem = sem_open("/sem", O_CREAT, S_IRWXU, 0); 

    if(sem == SEM_FAILED){
        perror("Error while init sem");
        exit(1);
    }
    
    printf("Initiated semaphore");

    pthread_attr_init(&attr);

    struct thread_info *tinfo = calloc(NUMBER_OF_THREADS, sizeof(*tinfo));

    for (int tnum = 0; tnum < NUMBER_OF_THREADS; tnum++) {
        tinfo[tnum].thread_num = tnum;
        pthread_create(&tinfo[tnum].thread_id, &attr, &handler1, &tinfo[tnum]);
    }

    printf("Initiated threads");

    for (int tnum = 0; tnum < NUMBER_OF_THREADS; tnum++) {
        s = pthread_join(tinfo[tnum].thread_id, &res);
        if (s != 0)
            perror("Error while joining pthreads");
            perror(s);
            exit(2);

        printf("Joined with thread %d; returned value was %s\n",
                tinfo[tnum].thread_num, (char *) res);
        free(res);      
    }
}