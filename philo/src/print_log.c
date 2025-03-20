


#include "../inc/philo.h"

void    write_log(t_program *program, int action, int philo_id)
{
    if(action == FORK)
        printf("%li %i has taken a fork\n", get_current_time(program), philo_id);
    else if (action == THINKING)
		printf("%li %i is thinking\n", get_current_time(program), philo_id);
}

