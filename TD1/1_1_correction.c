#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>		//pour utiliser le rand() => "man 3 rand" pour accéder aux pages du manuel sinon c'est la commande rand
#include <time.h>		//pour utiliser le time()
#include <unistd.h>		//usleep
#include <semaphore.h>  //uniquement pour version avec semaphore
#include <pthread.h>    //pour la gestion des threads et pour les mutex

#define ATTENTE_MIN 10000
#define ATTENTE_MAX 1000000

int mon_rand(int a, int b);

/* VERSION AVEC MUTEX */
void* thread_1(void* arg);
void* thread_2(void* arg);


/* VERSION AVEC MUTEX */
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER; // Initialise le Mutex 1
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER; // Initialise le Mutex 2

void  main_version_avec_mutex(void);
void* thread_1_mutex(void* arg);
void* thread_2_mutex(void* arg);


/* VERSION AVEC SEMAPHORE */
#define P(x) sem_wait(x)
#define V(x) sem_post(x)

sem_t *sem1, *sem2;
void  main_version_avec_sem(void);
void* thread_1_sem(void* arg);
void* thread_2_sem(void* arg);


/* ****************** */
/*        MAIN        */
/* ****************** */

int main(void)
{
	pthread_t mes_threads[2];

	srand(time(NULL));
	
	//EXECUTION SANS PROTECTION
	printf("\n** Lancement des threads sans protection **\n");
	pthread_create(&mes_threads[0],NULL,thread_1,NULL);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX)); //vérifier que tout fonctionne bien
	pthread_create(&mes_threads[1],NULL,thread_2,NULL);
	
	pthread_join(mes_threads[0],NULL);
	pthread_join(mes_threads[1],NULL);
	
	//EXECUTION AVEC MUTEX
	printf("\n\n** Lancement des threads avec mutex **\n");
	main_version_avec_mutex();
	
	//EXECUTION AVEC SEMAPHORE
	printf("\n\n** Lancement des threads avec semaphore **\n");
	main_version_avec_sem();

	printf("\n\n");
	return 0;
}

int mon_rand(int a, int b)
{
	//on suppose que b>a !
	return ( rand()%(b-a) ) + a;
}

/* ******************* */
/*   SANS PROTECTION   */
/* ******************* */
void* thread_1(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("je");
	
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf(" mes");
	
	return NULL;
}

void* thread_2(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf(" synchronise");
	
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf(" threads");
	
	return NULL;
}

/* ****************** */
/* VERSION AVEC MUTEX */
/* ****************** */
void main_version_avec_mutex(void)
{
	pthread_t mes_threads[2];
	
	//il faut bloquer le premier thread dès le départ
	int r = pthread_mutex_lock(&m1);
    if (r != 0) { // On vérifie l'exécution du lock
        perror("pthread_mutex_lock");
        exit(1);
    }
	pthread_mutex_lock(&m2);

	pthread_create(&mes_threads[0],NULL,thread_1_mutex,NULL);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	pthread_create(&mes_threads[1],NULL,thread_2_mutex,NULL);

	pthread_join(mes_threads[0],NULL);
	pthread_join(mes_threads[1],NULL);
	
	return;
}
void* thread_1_mutex(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("je ");
	pthread_mutex_unlock(&m1);
	pthread_mutex_lock(&m2);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("mes ");
	pthread_mutex_unlock(&m1);

	return NULL;
}

void* thread_2_mutex(void* arg)
{
	pthread_mutex_lock(&m1);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("synchronise ");
	pthread_mutex_unlock(&m2);
	pthread_mutex_lock(&m1);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("threads ");

	return NULL;
}

/* ********************** */
/* VERSION AVEC SEMAPHORE */
/* ********************** */
void main_version_avec_sem(void)
{
	pthread_t mes_threads[2];

    sem_unlink("sem1"); // Supprime la sémaphore du système
    sem_unlink("sem2"); // et permet de clean l'exécution
	
	if((sem1 = sem_open("sem1", O_CREAT|O_EXCL, S_IRWXU, 0)) == SEM_FAILED)
    {
        perror("Sem1 init failed");
        exit(1);
    }
    if((sem2 = sem_open("sem2", O_CREAT|O_EXCL, S_IRWXU, 0)) == SEM_FAILED)
    {
        perror("Sem2 init failed");
        exit(1);
    }
	
	pthread_create(&mes_threads[0],NULL,thread_1_sem,NULL);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	pthread_create(&mes_threads[1],NULL,thread_2_sem,NULL);	
	
	pthread_join(mes_threads[0],NULL);
	pthread_join(mes_threads[1],NULL);

	return;
}

void* thread_1_sem(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("je ");
	V(sem1);
	P(sem2);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("mes ");
	V(sem1);

	return NULL;
}

void* thread_2_sem(void* arg)
{
	P(sem1);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("synchronise ");
	V(sem2);
	P(sem1);
	usleep(mon_rand(ATTENTE_MIN,ATTENTE_MAX));
	printf("threads ");

	return NULL;
}