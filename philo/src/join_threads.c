



#include "../inc/philo.h"


void    join_threats(t_program *program)
{
    int i;
    i = 0;
    while(i < program->philos_and_forks)
    {
        pthread_join(program->philos[i].thread, NULL);
        i++;
    }
}