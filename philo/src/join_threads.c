



#include "../inc/philo.h"


void    join_threats(t_program *program)
{
    int i;
    i = 0;
    while(i < program->philos_and_forks)
    {
        // pthread_join(program->philo[i].philo_thread, NULL);
        //printf(" %d philo thread has ended", program->philo[i]->philo_id);
        printf(" %d philo thread has ended \n ", program->philo->philo_id );
        i++;
    }
}