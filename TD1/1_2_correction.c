#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>		//pour utiliser le rand() => "man 3 rand" pour accéder aux pages du manuel sinon c'est la commande rand
#include <time.h>		//pour utiliser le time()
#include <unistd.h>		//usleep
#include <semaphore.h>

#define NB_THREADS_REVEILLEUR 4

#define P(x) sem_wait(x)
#define V(x) sem_post(x)

sem_t sem;

int mon_rand(int a, int b);
void* thread_a_reveiller();
void* thread_reveilleur();

int main(void)
{
	int i;

	pthread_t thread_a_r;
	pthread_t threads_r[NB_THREADS_REVEILLEUR];

	pthread_create(&thread_a_r,NULL,thread_a_reveiller,NULL);

	for(i=0;i<NB_THREADS_REVEILLEUR;i++)
		pthread_create(&threads_r[i],NULL,thread_reveilleur,(void*)i);
	//gcc est de moins en moins tolérant et lève un warning sur le cast mais bon
	//il est important que le programmeur "confirme" le cast vers un (int)

	pthread_join(thread_a_r,NULL);
	for(i=0;i<NB_THREADS_REVEILLEUR;i++)
		pthread_join(threads_r[i],NULL);

	printf("\n");
	return 0;
}

int mon_rand(int a, int b)
{
	//on suppose que b>a !
	return ( rand()%(b-a) ) + a;
}

void* thread_a_reveiller()
{
	int i;
	printf("A reveiller en cours...\n");
	usleep(mon_rand(100000,1000000)); //simule un travail à faire
	for(i=0;i<NB_THREADS_REVEILLEUR;i++)
		P(&sem);
	printf("Reveilleurs termines\n");

	return NULL;
}

void* thread_reveilleur(void* num)
{
	int thread_num = (int) num; //pareil le compilo lève un warning aussi ici
	printf("\t Reveilleur %d en cours...\n",thread_num);
	usleep(mon_rand(100000,1000000)); //simule un travail à faire

	V(&sem);

	printf("\t Reveilleur %d termine !\n",thread_num);

	return NULL;
}