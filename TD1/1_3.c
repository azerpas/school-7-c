#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>		//pour utiliser le rand() => "man 3 rand" pour accéder aux pages du manuel sinon c'est la commande rand
#include <time.h>		//pour utiliser le time()

#define P(x) sem_wait(x) // wait before écriture
#define V(x) sem_post(x) // post after lecture
#define N 5

sem_t sem_case_libres;
sem_t sem_case_occupees;

int tampon[5];

void* ecrire_tampon(data);

void* lecture_tampon();

int main(){

    pthread_t ecrivain;
    pthread_t lecteur;

    sem_unlink(sem_case_libres);
    sem_unlink(sem_case_occupees);

    if((sem_case_libres = sem_open("sem", O_CREAT|O_EXCL, S_IRWXU, N)) == SEM_FAILED)
    {
        perror("sem init failed");
        exit(1);
    }

    if((sem_case_occupees = sem_open("sem", O_CREAT|O_EXCL, S_IRWXU, 0)) == SEM_FAILED)
    {
        perror("sem init failed");
        exit(1);
    }

    pthread_create(&ecrivain, NULL, ecrire_tampon(1), NULL);
    pthread_create(&lecteur, NULL, lecture_tampon, NULL);

    pthread_join(&ecrivain, NULL);
    pthread_join(&lecteur, NULL);

}

void* ecrire_tampon(int data)
{
    P(sem_case_libres);
    tampon[0] = data;
    V(sem_case_occupees);
}

void* lecture_tampon(void *arg)
{
    P(sem_case_occupees);
    printf("%d", tampon[0]);
    V(sem_case_libres);
}