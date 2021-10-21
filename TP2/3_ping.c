#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Please input the pid\n");
        exit(1);
    }
    else
    {
        kill(atoi(argv[1]), SIGUSR1);
        printf("Signal 1 sent\n");
        usleep(500);
        for (size_t i = 0; i < 2; i++)
        {
            kill(atoi(argv[1]), SIGUSR1);
        }
        printf("Two signals sent\n");
        usleep(500);
        for (size_t i = 0; i < 3; i++)
        {
            kill(atoi(argv[1]), SIGUSR1);
        }
        printf("Three signals sent\n");
    } 
}