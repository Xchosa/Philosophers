/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:25:07 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/25 16:08:08 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void	init_arguments_in_programm(t_program *program, char **argv, int argc)
{
    program->start_time = ft_get_time_millis();
	program->philos_and_forks = ft_atoi(argv[1]);
	program->time_to_die = ft_atol(argv[2]);
	program->time_to_eat = ft_atol(argv[3]);
	program->time_to_sleep = ft_atol(argv[4]);
	if (argc == 5)
	{
		program->nbr_of_times_philo_must_eat = ft_atol(argv[5]);
		program->bool_meal_limit = true;
	}
	else
	{
		program->nbr_of_times_philo_must_eat = 0;
		program->bool_meal_limit = false;
	}
}
void	initialise_mutex_in_program(t_program *program)
{
	program->all_philos_alive = true;
	pthread_mutex_init(&program->mutex_all_philos_alive, NULL);
	pthread_mutex_init(&program->mutex_print, NULL);
	pthread_mutex_init(&program->mutex_meals_to_take, NULL);
	pthread_mutex_init(&program->mutex_start_time, NULL);
	// pthread_mutex_init(&program->time_mutex, NULL);
}

// each fork gets a mutex 

void	init_forks(t_program *program)
{
	int i;
	
	i = 0;
	while(i < program->philos_and_forks)
	{
		program->forks[i].fork_bool = false;
		pthread_mutex_init(&program->forks[i].fork_mutex, NULL);
		i++;
	}
}

void	init_philos(t_program *program)
{
	int i;
	
	i = 0;
	while(i < program->philos_and_forks)
	{
		program->philo[i].philo_id = i + 1;
		program->philo[i].taken_meals = 0;
		program->philo[i].philo_alive = true;
		program->philo[i].time_last_eaten = get_current_time(program);
		program->philo[i].program = program;
		program->philo[i].right_fork = &program->forks[i];
		program->philo[i].left_fork =
			&program->forks[(i - 1 + program->philos_and_forks) % program->philos_and_forks]; 
		
		
		printf("Philo_id %d: right fork %p | left fork %p \n ", 
            program->philo[i].philo_id, 
            program->philo[i].right_fork,
            program->philo[i].left_fork);
		i++;
	}
}
