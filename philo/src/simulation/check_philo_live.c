


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
		pthread_mutex_unlock(&program->mutex_all_philos_alive);
		philo_alive = false;
	}
	pthread_mutex_unlock(&philo->mutex_time_last_eaten);
	return(philo_alive);
}