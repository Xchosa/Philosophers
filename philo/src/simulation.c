/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:36:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/24 16:44:09 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// simulations when a philo eats, thinks or sleeps updates last_time_eaten every time
void	simulation(t_program *program, t_philo *philo)
{
	while(1)
	{
			deathcheck(philo, program);
			if((philo->philo_id % 2 ) != 0)
				philo_eats_right_first(philo, program);
			else 
				philo_eats_left_first(philo, program);
			if(philo->philo_alive == false)
			{
				printf("philo %d died ", philo->philo_id);
				return;
			}
			if (program->nbr_of_times_philo_must_eat == program->philo->taken_meals)// data race? weil monitor lesen und schreiben muss 
			{
				// 
				// own+print(program->philo

				// print_mutex blocken 
			}
			philo_sleeps(philo, program);
			philo_thinks(philo, program);
			if(program->nbr_of_times_philo_must_eat > 0 && philo->taken_meals >= program->nbr_of_times_philo_must_eat)	
				return ;
			
	}
}
// brauche keinen monitor - jeder philo soll selber checken ob er satt oder tod ist. dann print_mutex blocken, so das keiner danach mehr drucken kann
// mutex
// fork
// zeit
//printen 
// seperate mutex 
// print_mutex im program 



void	philo_eats_right_first(t_philo *philo, t_program *program)
{
	while(1)
	{
		if(lifespan(program, philo) != 0)
			program->philo_died = true;
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		if(philo->right_fork->fork_bool == false && philo->left_fork->fork_bool == 0)
		{
			philo->right_fork->fork_bool = true;
			printf(" %llu , %d has taken a Fork \n", get_current_time(program), philo->philo_id);
			philo->left_fork->fork_bool = true;
			printf(" %llu , %d has taken a Fork \n", get_current_time(program), philo->philo_id);
			printf(" %llu , %d is eating \n", get_current_time(program), philo->philo_id);
			usleep(program->time_to_eat * 1000);
			philo->left_fork->fork_bool = false;
			philo->right_fork->fork_bool = false;
			philo->time_last_eaten = get_current_time(program);
			philo->taken_meals++;
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		return;
	}
}

void philo_eats_left_first(t_philo *philo, t_program *program)
{
	while(1)
	{
		if(lifespan(program, philo) != 0)
			program->philo_died = true;
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		if(philo->left_fork->fork_bool == false && philo->right_fork->fork_bool == false)
		{
			philo->left_fork->fork_bool = true;
			printf(" %llu , %d has taken a Fork \n", get_current_time(program), philo->philo_id);
			philo->right_fork->fork_bool = true;
			printf(" %llu , %d has taken a Fork \n", get_current_time(program), philo->philo_id);
			printf(" %llu , %d is eating \n", get_current_time(program), philo->philo_id);
			usleep(program->time_to_eat * 1000);
			philo->left_fork->fork_bool = false;
			philo->right_fork->fork_bool = false;
			philo->time_last_eaten = get_current_time(program);
			philo->taken_meals++;
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		return;
	}
}

void	philo_sleeps(t_philo *philo, t_program *program)
{
	printf(" %llu , %d is sleeping \n", get_current_time(program) ,philo->philo_id);
	usleep(program->time_to_sleep * 1000);
}
// waits as long as it takes time to eat 
// only than tries to eat again. 
void	philo_thinks(t_philo *philo, t_program *program)
{
	printf(" %llu , %d is thinking \n", get_current_time(program) , philo->philo_id);
	usleep(program->time_to_die - (get_current_time(program) - philo->time_last_eaten));
}


void deathcheck(t_philo *philo, t_program *program)
{
	if (program->time_to_die < (get_current_time(program) - philo->time_last_eaten))
	{
		program->philo_died = true;
		philo->philo_alive = false;
		printf("philo %d died ", philo->philo_id);
			return;
	}
}

// main threat is not in the simulation. loops through the philo array and checks if last_time_eaten is bigger than  time_to_die
void	monitor(t_program *program)
{

	// t_program *program;

	// program= (t_program *)mointor_arg;

	int i;
    usleep(1000);
    i = 0;
	while(1)
	{
		i = 0;
		while(i < program->philos_and_forks)
		{
			if(program->philo[i].philo_alive == false)
				{
					printf("%d philo is dead ", program->philo[i].philo_alive);
					return;
				}
			deathcheck(program->philo + i, program);
			if (program->philo_died == true)
				return;
			// printf("%ld taken meals \n", program->philo[i].taken_meals);
			//printf("%ld meals to be taken \n", program->nbr_of_times_philo_must_eat);
			if (program->nbr_of_times_philo_must_eat == program->philo->taken_meals)// data race? weil monitor lesen und schreiben muss 
				return;
			i++;
		}
	}
	return ;
}

