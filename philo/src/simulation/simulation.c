/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:36:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/31 10:00:10 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"


void	philo_sleeps(t_philo *philo, t_program *program)
{
	print_save(program, philo, SLEEP);
	usleep(program->time_to_sleep * 1000);
}

void	philo_thinks(t_philo *philo, t_program *program)
{
	print_save(program, philo, THINK);
	usleep(program->time_to_die /4 *1000 );
}
/*
printf(" think time: %lu \n", program->time_to_die - 
(get_current_time(program) - philo->time_last_eaten))
*/

bool	check_is_philo_full(t_program *program, t_philo *philo)
{
	bool	philo_not_full;

	philo_not_full = true;
	pthread_mutex_lock(&philo->mutex_taken_meals);
	pthread_mutex_lock(&program->mutex_meals_to_take);
	if (program->bool_meal_limit == false)
		philo_not_full = true;
	else
		philo_not_full = (philo->taken_meals < program->nbr_of_times_philo_must_eat);
	pthread_mutex_unlock(&program->mutex_meals_to_take);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
	return (philo_not_full);
}
