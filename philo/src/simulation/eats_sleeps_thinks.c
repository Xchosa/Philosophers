/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats_sleeps_thinks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:36:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/07 16:37:15 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	philo_eats(t_philo *philo, t_program *program)
{
	while (1)
	{
		if (check_philo_alive(philo, program) == false)
			return ;
		choose_fork_to_lock(philo);
		if (philo->right_fork->fork_bool == false && \
			philo->left_fork->fork_bool == false)
		{
			if (check_philo_alive(philo, program) == false)
			{
				choose_fork_to_unlock(philo);
				return ;
			}
			update_eaten_meals_nbr_and_time(philo, program);
			using_forks_to_eat(philo, program);
			fork_back_on_table(philo);
			choose_fork_to_unlock(philo);
			return ;
		}
		else
		{
			choose_fork_to_unlock(philo);
			usleep(2 * 1000);
		}
	}
}

void	philo_sleeps(t_philo *philo, t_program *program)
{
	print_save(program, philo, SLEEP);
	usleep(program->time_to_sleep * 1000);
}

void	philo_thinks(t_philo *philo, t_program *program)
{
	if (check_philo_alive(philo, program) == false)
		return ;
	print_save(program, philo, THINK);
}

bool	check_is_philo_full(t_program *program, t_philo *philo)
{
	bool	philo_not_full;

	philo_not_full = true;
	pthread_mutex_lock(&philo->mutex_taken_meals);
	pthread_mutex_lock(&program->mutex_meals_to_take);
	if (program->bool_meal_limit == false)
		philo_not_full = true;
	else
		philo_not_full = (philo->taken_meals \
			< program->nbr_of_times_philo_must_eat);
	pthread_mutex_unlock(&program->mutex_meals_to_take);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
	return (philo_not_full);
}

void	handle_one_philo(t_philo *philo, t_program *program)
{
	usleep(program->time_to_die * 1000);
	print_save(program, philo, DEAD);
}
