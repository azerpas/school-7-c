#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define CONSTANT_PROC 15000000 

void do_work(unsigned int nb_secondes);
void handler();

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; // Initialise le Mutex 
int interuptions = 0; // Init le compteur d'interruptions intervenues pendant une routine

int main()
{
    signal(SIGUSR1, handler);
    printf("My pid is %d\n", getpid());
    while (1)
    {
        printf("En attente...\n");
        pause();
        if(interuptions > 0){
            do_work(100);
            pthread_mutex_lock(&m);
            interuptions--;
            pthread_mutex_unlock(&m);
        }
    }
}

void do_work(unsigned int nb_secondes)
{
	unsigned long long i = CONSTANT_PROC * nb_secondes;
	while(i>0)
	{
		asm volatile("nop");
		i--;
	}
	return;
}

void handler()
{
    printf("Signal triggered!\n");
    do_work(4000);
    // Signal or ?
}