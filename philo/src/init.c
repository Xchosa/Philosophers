/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:25:07 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 16:30:54 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void init_programm(t_program *program, char **argv, int argc)
{
    program->start_time = ft_get_time();
	program->philos_and_forks = atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		program->nbr_of_times_philo_must_eat = ft_atoi(argv[5]);
	program->philo_died = false;
	pthread_mutex_init(&program->sleep_mutex, NULL);
	pthread_mutex_init(&program->print_mutex, NULL);
	pthread_mutex_init(&program->eats_mutex, NULL);
	pthread_mutex_init(&program->think_mutex, NULL);
	init_fork(program);
}

// each fork gets a mutex 
void	init_fork(t_program *program)
{
	int	i;

	i = 0;
	while(i < program->philos_and_forks)
	{
		pthread_mutex_init(&program->forks[i], NULL);
		i++;
	}
}


void	init_philos(t_program *program)
{
	int i;
	
	i = 0;
	while(i < program->philos_and_forks)
	{
		program->philo[i].philo_id = i;
		program->philo[i].time_last_eaten = get_current_time(program);
		program->philo[i].program = program;
		i++;
		printf("philo has eaten last time %ld \n", program->philo[i].time_last_eaten);
	}
}

uint_fast64_t 	ft_get_time()
{
	struct timeval	time;
	uint_fast64_t	time_milisec;
	// suseconds_t  tv_usec;  /* Microseconds */
	if(gettimeofday(&time,NULL)!= 0)
		perror("faild to find time of the day");
	time_milisec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return(time_milisec);
}

uint_fast64_t	get_current_time(t_program *program)
{
	return(program->start_time - ft_get_time());
}