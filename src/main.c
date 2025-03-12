



#include "../inc/philo.h"


int main()
{
    t_progam   prog;
    t_semaphore  chopstick[5]

    while(true)
    {
        wait(chopstick[i]);
        wait(chopstick[i+1] % 5); // 5th philo chob grabs nr 1 again
        // eat
        signal(chopstick[i]);
        signal(chopstick[i +1] % 5)

        // think (while this is true)
    }
}


// can not pick up fork at the same time
//pick_up_fork
// only available forks
// no philo should try eating 
// eat think slepp 


// 

// // intialize mutex
// phtread_mutex_intit();
// // destroy
// pthread_mutex_destroy();

// //lock the mutex before accessing the shared resource
// pthread_mutex_lock();

// pthread_mutex_unlock()