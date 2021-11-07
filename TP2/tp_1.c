#include <stdio.h>
#include <signal.h>
#include <time.h>

#define CONSTANT_PROC 35000000

void do_work(unsigned int nb_secondes);

int main()
{
    do_work(4000);
	return 0;
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