#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler()
{
    printf("Signal triggered!\n");
}

int main()
{
    signal(SIGUSR1, handler);
    printf("My pid is %d\n", getpid());
    while (1)
    {
        printf("En attente...\n");
        pause();
    }
}