



#include "../inc/philo.h"


int main(int argc, char **argv)
{
    t_program   progam;

    if (check_arg(argc, argv) != 0)
        return ;
    init_programm(&progam, argv);
    // pthread_mutex_init(&mutex, Null)
    p_thread_create();
        //pthread_mutex_lock();
        // operation
        // pthread_mutex_unlock()

    // pthread_join(&mutex)
   // pthread_mutex_destroy(&mutex);
}


// can not pick up fork at the same time
//pick_up_fork
// only available forks
// no philo should try eating 
// eat think slepp 


// Initialization: The program starts by checking the input arguments and initializing the data structures.
// Philosopher Creation: It creates philosopher threads and starts their routines.
// Monitoring: A monitor thread checks the status of philosophers to detect if any philosopher has died or if all philosophers are full.
// Joining Threads: The main thread waits for all philosopher threads to finish.
// Cleanup: Finally, it cleans up resources like mutexes.


void init_programm(t_program *program, char **argv)
{
    program->

}
