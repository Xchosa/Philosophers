
#include "../../inc/philo.h"

bool check_philo_alive(t_philo *philo, t_program *program)
{
	bool philo_alive;
	
	philo_alive = true;
	pthread_mutex_lock(&program->mutex_all_philos_alive);
	if(program->all_philos_alive == false)
	{
		pthread_mutex_unlock(&program->mutex_all_philos_alive);
		return(philo_alive = false);
	}
	pthread_mutex_lock(&philo->mutex_time_last_eaten);
	if (program->time_to_die < (get_current_time(program) - philo->time_last_eaten))
	{
		philo->philo_alive = false;
		print_save(program, philo, DEAD);
		program->all_philos_alive = false;
        pthread_mutex_unlock(&philo->mutex_time_last_eaten);
		pthread_mutex_unlock(&program->mutex_all_philos_alive);
		return(philo_alive = false);
	}
	pthread_mutex_unlock(&philo->mutex_time_last_eaten);
    pthread_mutex_unlock(&program->mutex_all_philos_alive);
	return(philo_alive = true);
}

void    initalize_philo_lifetime(t_philo *philo, t_program *program)
{
	pthread_mutex_lock(&philo->mutex_taken_meals);
	philo->time_last_eaten = get_current_time(program);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
}
