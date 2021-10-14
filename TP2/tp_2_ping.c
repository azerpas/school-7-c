#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

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
        printf("Signal sent\n");
    }
}