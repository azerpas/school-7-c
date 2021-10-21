/*Correction MODULE SYSTEMES TEMPS REEL - EFREI - CALCADO FABIEN*/

#include <stdio.h>
#include <signal.h>
#include <time.h>

#define CONSTANT_PROC 15000000 //A determiner pour votre machine ! ==>
                              //peut �tre fait de mani�re automatique mais ce n'est pas le sujet du TP

void do_work(unsigned int nb_secondes);

/*fonction simulant un travail � effectuer (attente active)*/
void do_work(unsigned int nb_secondes)
{
	unsigned long long i = CONSTANT_PROC * nb_secondes; //attention � ne pas utiliser un int pour �viter un overflow

	while(i>0)
	{
		asm volatile("nop");
		i--;
	}

	return;
}

/* MAIN */
int main()
{
    //ne pas faire d'affichage avec un printf("") sinon il y aura des fluctuations encore plus importantes sur le temps d'ex�cution
    do_work(4000);
	return 0;
}