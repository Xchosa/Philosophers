



#include "../inc/philo.h"


void    print_program_struct(t_program *program)
{
    printf("%ld start time \n", program->start_time);
    printf("%ld philos_and forks \n", program->philos_and_forks);
    printf("%ld time to die\n ",program->time_to_die);
    printf("%ld time to eat\n ",program->time_to_eat);
    printf("%ld time to sleep\n ",program->time_to_sleep);
    int i;
    i = 0;
	while (i < program->philos_and_forks)
	{
		printf("%d id philos are living\n", program->philo[i].philo_id );
		i++;
	}
}