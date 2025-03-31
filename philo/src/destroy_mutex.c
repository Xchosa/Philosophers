/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:48 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/31 11:29:10 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	dextroy_thread_mutex(t_program *program)
{
	int	i;

	pthread_mutex_destroy(&program->mutex_start_time);
	pthread_mutex_destroy(&program->mutex_meals_to_take);
	pthread_mutex_destroy(&program->mutex_all_philos_alive);
	pthread_mutex_destroy(&program->mutex_print);
	i = 0;
	while (i < program->philos_and_forks)
	{
		pthread_mutex_destroy(&program->philo[i].mutex_taken_meals);
		pthread_mutex_destroy(&program->philo[i].mutex_time_last_eaten);
        pthread_mutex_destroy(&program->forks[i].fork_mutex);
        i++;
	}
}

// void	free_everything(t_program *program)
// {
// 	int i;

// 	i = 0;
// 	while(i < program->philos_and_forks)
// 	{
// 		free(&program->philo[i]);
// 		free(&program->forks[i]);
// 		i++;
// 	}
// }
