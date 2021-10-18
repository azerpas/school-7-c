#include <signal.h>
#include <time.h>

static int i = 0;

void handler(){
    printf("Trying for the %d time\n", ++i);
}

int main(int argc, char const *argv[])
{
    timer_t timer_id;
    struct sigevent sig;

    sig.sigev_notify = SIGEV_THREAD;
    sig.sigev_notify_function = handler;

    int res = timer_create(CLOCK_REALTIME, &sig, &timer_id);

    if(res == 0){
        struct itimerspec in, out;
        in.it_value.tv_sec = 1;
        in.it_value.tv_nsec = 0;
        in.it_interval.tv_sec = 0;
        in.it_interval.tv_nsec = 100000000;
        res = timer_settime(timer_id, 0, &in, &out);
        if(res == 0){
            printf("Successfully created timer\n");
            sleep(2);
        }else{
            printf("Error while setting timer, failed: %d\n", errno);
        }
        timer_delete(timer_id);
        return 0;
    }
    
    return -1;
}
