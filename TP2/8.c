// Par rapport au tableau, somme des ratios Execution / Temp
// Ex ici: 
// - Temps total: 2 + 3 + 4 = 9
// - Actions: 0.33 + 1 + 2 = 3.33
// les actions prennent bien le temps 

// T2() do_work
// T3() do_work
// T4() do_work
// PAUSE() -> cassé par Create Timer

// Create Timer permet de redémarrer sur une période temp

#include <signal.h>
#include <time.h>

void t2(int temps);
void t3(int temps);
void t4(int temps);

int main(int argc, char const *argv[])
{
    struct sigevent sig;
    timer_t timer_id;
    sig.sigev_notify = SIGEV_THREAD;
    sig.sigev_notify_function = handler;

    int res = timer_create(CLOCK_REALTIME, &sig, &timer_id);
    if(res == 0){
        struct itimerspec in, out;
        in.it_value.tv_sec = 1;
        in.it_value.tv_nsec = 0;
        in.it_interval.tv_sec = 0;
        in.it_interval.tv_nsec = 150000000;
        res = timer_settime(timer_id, 0, &in, &out);
        if(res == 0){
            printf("Successfully created timer\n");
            sleep(2);
        }else{
            printf("Error while setting timer, failed: %d\n", errno);
        }
        while(1){
            t2(333);
            t3(666);
            pause(); // Each 1.5s with timer
            t3(333);
            t4(666);
            pause(); // Each 1.5s with timer
        }
        return 0;
    }
}

void t2(int temps){
    do_work(temps);
}

void t3(int temps){
    do_work(temps);
}

void t4(int temps){
    do_work(temps);
}


// 2 - 3 ex synchro
// questions de cours classiques (un peu du TP)
//      - questions synchro
// plan d'ordonnancement