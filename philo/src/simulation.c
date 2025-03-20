/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:36:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/20 16:09:50 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// simulations when a philo eats, thinks or sleeps updates last_time_eaten every time
void	simulation(t_program *program, t_philo *philo)
{
	ft_get_time_ms();
	// update every circle 
	int i;
	while(1)
	{
		i = 0;
		while(i < program->philos_and_forks)
		{
			// functions for ever update
			// implement enoms?
			philo_eats(program->philo[i].philo_thread);
			philo_sleeps(program->philo[i].philo_thread);
			program->philo[i].taken_meals++;
			i++;
		}
	}
	//
}

void	philo_eats(t_program *philo)
{
	printf(" %lld , %d has taken a Fork ", get_current_time(program) ,  program->philo[i].philo_id );
	printf(" %lld , %d is eating ", get_current_time(program) ,  program->philo[i].philo_id );
	usleep(program->time_to_eat * 1000);
}
void	philo_sleep(t_philo *philo)
{
	printf(" %lld , %d is sleeping ", get_current_time(program) ,  philo.philo_id );
	usleep(program->time_to_sleep * 1000);
}

// main threat is not in the simulation. loops through the philo array and checks if last_time_eaten is bigger than  time_to_die
void	monitor(t_program *program)
{
	int i;
    
    i = 0;
	while(1)
	{
		i = 0;
		while(i < program->philos_and_forks)
		{
			if (program->time_to_eat &program->philo_died == true) // setzt philo auf dead // last_time_eaten vgl mit time_to_die 
				return;
			if (program->nbr_of_times_philo_must_eat == program->philo->taken_meals)// data race? weil monitor lesen und schreiben muss 
				return;
			i++;
			
		}
	}
}