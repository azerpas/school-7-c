#include <signal.h>
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdlib.h>

#define CONSTANT_PROC 352000000

void do_work(unsigned int nb_secondes);

void handler(){
    printf("Doing work...\n");
    alarm(1);
    do_work(500);
    signal(SIGALRM, handler);
}

int main(int argc, char const *argv[])
{
    signal(SIGALRM, handler);
    alarm(1);
    int n = 0;
    while(1){ 
        n++;
    }
    return 0;
}

void do_work(unsigned int nb_secondes)
{
	unsigned int i = CONSTANT_PROC * nb_secondes;
	while(i>0)
	{
		asm volatile("nop");
		i--;
	}
	return;
}