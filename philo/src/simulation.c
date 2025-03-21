/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:36:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/20 16:42:48 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// simulations when a philo eats, thinks or sleeps updates last_time_eaten every time
void	simulation(t_program *program, t_philo *philo)
{
	// ft_get_time_ms();
	// // update every circle 
	int i;
	int tester = 0;
	while(1)
	{
		i = 0;
		while(i < program->philos_and_forks)
		{
			// functions for ever update
			// implement enoms?
			philo_eats(philo, program);
			philo_sleeps(philo, program);
			philo->taken_meals++;
			philo_thinks(philo, program);
			i++;
			if(program->nbr_of_times_philo_must_eat == philo->taken_meals)	
				return;
			tester++;
			if (tester == 40)
				return;
		}
		
	}
	//
}

void	philo_eats(t_philo *philo, t_program *program)
{
	printf(" %ld , %d has taken a Fork \n", get_current_time(program), philo->philo_id);
	
	printf(" %ld , %d is eating \n", get_current_time(program),   philo->philo_id);
	usleep(program->time_to_eat * 1000);
}
void	philo_sleeps(t_philo *philo, t_program *program)
{
	printf(" %ld , %d is sleeping \n", get_current_time(program) ,philo->philo_id);
	usleep(program->time_to_sleep * 1000);
}
// waits as long as it takes time to eat 
// only than tries to eat again. 
void	philo_thinks(t_philo *philo, t_program *program)
{
	printf(" %ld , %d is thinking \n", get_current_time(program) , philo->philo_id);
	usleep(program->time_to_eat * 1000);
}


// main threat is not in the simulation. loops through the philo array and checks if last_time_eaten is bigger than  time_to_die
void	monitor(t_program *program)
{
	int i;
    
    i = 0;
	int tester = 0;
	while(1)
	{
		i = 0;
		while(i < program->philos_and_forks)
		{
			// if (program->time_to_eat , &program->philo_died == true) // setzt philo auf dead // last_time_eaten vgl mit time_to_die 
			// 	return;
			printf("%ld taken meals \n", program->philo[i].taken_meals);
			printf("%ld meals to be taken \n", program->nbr_of_times_philo_must_eat);
			if (program->nbr_of_times_philo_must_eat == program->philo->taken_meals)// data race? weil monitor lesen und schreiben muss 
				return;
			i++;
			if(tester == 40)
				return ;
			tester++;
		}
	}
	return ;
}