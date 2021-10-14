#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

void do_work(unsigned int duration){
    sleep(duration);
}

int main(){
    printf("Starting work\n");
    time_t before = time(NULL);
    do_work(3);
    time_t after = time(NULL);
    printf("Finished work in %ld", after-before);
}