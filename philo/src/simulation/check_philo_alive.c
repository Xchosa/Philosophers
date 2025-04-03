/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_alive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:48:53 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/03 09:56:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

bool	check_philo_alive(t_philo *philo, t_program *program)
{
	bool	philo_alive;

	philo_alive = true;
	pthread_mutex_lock(&program->mutex_all_philos_alive);
	if (program->all_philos_alive == false)
	{
		pthread_mutex_unlock(&program->mutex_all_philos_alive);
		return (philo_alive = false);
	}
	pthread_mutex_lock(&philo->mutex_time_last_eaten);
	if (program->time_to_die < (get_current_time(program) - philo->time_last_eaten))
	{
		philo->philo_alive = false;
		print_save(program, philo, DEAD);
		program->all_philos_alive = false;
		pthread_mutex_unlock(&philo->mutex_time_last_eaten);
		pthread_mutex_unlock(&program->mutex_all_philos_alive);
		return (philo_alive = false);
	}
	pthread_mutex_unlock(&philo->mutex_time_last_eaten);
    pthread_mutex_unlock(&program->mutex_all_philos_alive);
	return (philo_alive = true);
}

// printf("philo id %d time last eaten %ld\n",
// philo->philo_id, philo->time_last_eaten);
// no cases 
void	initalize_philo_lifetime(t_philo *philo, t_program *program)
{
	pthread_mutex_lock(&philo->mutex_taken_meals);
	philo->time_last_eaten = get_current_time(program);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
}

// printf("philo id %d time to die %ld | difference fresh %ld  | current time %ld | - last_time eaten %ld \n",
		// philo->philo_id, program->time_to_die,(get_current_time(program) - philo->time_last_eaten),
		// get_current_time(program),  philo->time_last_eaten);
// printf("philo id %d time last eaten %ld\n",philo->philo_id, philo->time_last_eaten);