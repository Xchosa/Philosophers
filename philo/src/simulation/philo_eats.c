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


void	fork_back_on_table(t_philo *philo)
{
	philo->left_fork->fork_bool = false;
	philo->right_fork->fork_bool = false;
}

void	update_eaten_meals_Nbr_and_time(t_philo *philo, t_program *program)
{
	pthread_mutex_lock(&philo->mutex_taken_meals);
	pthread_mutex_lock(&program->mutex_meals_to_take);
	philo->time_last_eaten = get_current_time(program);
	philo->taken_meals++;
	pthread_mutex_unlock(&program->mutex_meals_to_take);
	pthread_mutex_unlock(&philo->mutex_taken_meals);
}


void choose_fork_to_lock(t_philo *philo)
{
	if (&philo->right_fork->fork_mutex < &philo->left_fork->fork_mutex)
	{
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
	}
    else
	{
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
    	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	}
}
void choose_fork_to_unlock(t_philo *philo)
{
	if (&philo->right_fork->fork_mutex < &philo->left_fork->fork_mutex)
	{
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
    	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	}
    else
	{
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	}
}

void philo_eats(t_philo *philo, t_program *program)
{
    while(1)
    {
        if(check_philo_alive(philo, program) == false)
            return;
		choose_fork_to_lock(philo);
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
			choose_fork_to_unlock(philo);
            return;
        }
        else
        {
			choose_fork_to_unlock(philo);
		}
        usleep(2*1000);
    }
}