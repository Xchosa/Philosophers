/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:25:07 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 16:25:09 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"




void init_programm(t_program *program, char **argv, int argc)
{
    program->philos_and_forks = atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		program->nbr_of_times_philo_must_eat = ft_atoi(argv[5]);
	program->philo_died = false;
	pthread_mutex_init(&program->meal_mutex, NULL);
	pthread_mutex_intit(&program->sleep_mutex, NULL);
	pthread_mutex_init(&program->print_mutex, NULL);
	pthread_mutex_init(&program->death_mutex, NULL);
	init_fork(program);
}

void	init_fork(t_program *program)
{
	int	i;

	i = 0;
	while(i < program->philos_and_forks)
	{
		pthread_mutex_intit(&program->forks[i], NULL);
		i++;
	}
}
