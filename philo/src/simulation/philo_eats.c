/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:25:14 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/26 16:43:08 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

// watch https://www.youtube.com/watch?v=raLCgPK-Igc
// reduce mutex

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
	// printf("philo %d  is not full %llu \n", philo->philo_id, philo->taken_meals );
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
		if(check_philo_alive(philo,program )== false)
			return;
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
			pthread_mutex_unlock(&philo->right_fork->fork_mutex);
			pthread_mutex_unlock(&philo->left_fork->fork_mutex);
			return ;
		}
		else
		{
			pthread_mutex_unlock(&philo->right_fork->fork_mutex);
			pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		}
	}
}

void philo_eats_left_first(t_philo *philo, t_program *program)
{
	while(1)
	{
		if(check_philo_alive(philo,program )== false)
			return;
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
			pthread_mutex_unlock(&philo->right_fork->fork_mutex);
			pthread_mutex_unlock(&philo->left_fork->fork_mutex);
			return ;
		}
		else
		{
			pthread_mutex_unlock(&philo->right_fork->fork_mutex);
			pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		}
	}
}

void	fork_back_on_table(t_philo *philo)
{
	philo->left_fork->fork_bool = false;
	philo->right_fork->fork_bool = false;
}
void	update_eaten_meals_Nbr_and_time(t_philo *philo, t_program *program)
{
	pthread_mutex_lock(&program->mutex_meals_to_take);
	pthread_mutex_lock(&philo->mutex_taken_meals);
	philo->time_last_eaten = get_current_time(program);
	philo->taken_meals++;
	pthread_mutex_unlock(&program->mutex_meals_to_take);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
}