/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:25:14 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/25 15:50:50 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"


bool	check_is_philo_full(t_program *program, t_philo *philo)
{
	bool philo_is_not_full;
	
	philo_is_not_full = true;
	pthread_mutex_lock(&philo->mutex_taken_meals);
	pthread_mutex_lock(&program->mutex_meals_to_take);
	if (program->bool_meal_limit == false)
		philo_is_not_full = true;
	if (philo->taken_meals < program->nbr_of_times_philo_must_eat)
		philo_is_not_full = true;
	if (philo->taken_meals >= program->nbr_of_times_philo_must_eat)
	{
		philo_is_not_full = false;
	}
	pthread_mutex_unlock(&program->mutex_meals_to_take);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
	return (philo_is_not_full);
}
// ein mutex reicht - alle variablen dahinter werden geblockt
// kein anderer thread kann diese variablen lesen, schreiben
void	philo_eats_right_first(t_philo *philo, t_program *program)
{
	while(1)
	{
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		if(philo->right_fork->fork_bool == false && philo->left_fork->fork_bool == false)
		{
			philo->right_fork->fork_bool = true;
			print_save(program, philo, FORK);
			philo->left_fork->fork_bool = true;
			print_save(program, philo, FORK);
			print_save(program, philo, EAT);
			usleep(program->time_to_eat * 1000);
			fork_back_on_table(philo);
			update_eaten_meals_Nbr_and_time(philo, program);
		}
		else
		{
			pthread_mutex_unlock(&philo->right_fork->fork_mutex);
			pthread_mutex_unlock(&philo->left_fork->fork_mutex);
			break ;
		}
		// pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		printf(" philo %d waits %lu \n", philo->philo_id, ((program->time_to_eat / 2)));
		usleep((program->time_to_eat / 2));
	}
}

void	fork_back_on_table(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	philo->left_fork->fork_bool = false;
	philo->right_fork->fork_bool = false;
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
}
void	update_eaten_meals_Nbr_and_time(t_philo *philo, t_program *program)
{
	// pthread_mutex_lock(&program->mutex_meals_to_take);
	pthread_mutex_lock(&philo->mutex_taken_meals);
	philo->time_last_eaten = get_current_time(program);
	philo->taken_meals++;
	// pthread_mutex_unlock(&program->mutex_meals_to_take);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
}

void philo_eats_left_first(t_philo *philo, t_program *program)
{
	while(1)
	{
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		if(philo->left_fork->fork_bool == false && philo->right_fork->fork_bool == false)
		{
			philo->left_fork->fork_bool = true;
			print_save(program, philo, FORK);
			philo->right_fork->fork_bool = true;
			print_save(program, philo, FORK);
			print_save(program, philo, EAT);
			usleep(program->time_to_eat * 1000);
			fork_back_on_table(philo);
			update_eaten_meals_Nbr_and_time(philo, program);
		}
		else
		{
			pthread_mutex_unlock(&philo->right_fork->fork_mutex);
			pthread_mutex_unlock(&philo->left_fork->fork_mutex);
			break
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		return;
	}
}