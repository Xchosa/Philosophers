/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:36:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/26 16:44:01 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

// simulations when a philo eats, thinks or sleeps updates last_time_eaten every time
void	simulation(t_program *program, t_philo *philo)
{
	// forks are still blocked for 5 
	// philo 5 jumps straight into sleeping - no fork free 
	// if philo id is ungerade und philo id 1 extra check
	// debug with c debugger vs
	while(1)
	{
		if(check_philo_alive(philo,program )== false)
			return;
		// printf(" philo %d in simulation part 1\n", philo->philo_id);
		// print_fork_state(program, "BEFORE");
		if((philo->philo_id % 2 ) != 0)
			philo_eats_right_first(philo, program);
		else 
			philo_eats_left_first(philo, program);
		// print_fork_state(program, "AFTER");
		printf("sleep %d \n", philo->philo_id);
		philo_sleeps(philo, program);
		philo_thinks(philo, program);
		// print_fork_state(program, "AFTER");
		if (check_is_philo_full(program, philo) == false)
			return ;
		// debug_log(program, philo, "one_round");
	}
}

void	philo_sleeps(t_philo *philo, t_program *program)
{
	print_save(program, philo, SLEEP);
	printf(" sleep time: %llu \n", program->time_to_sleep);
	usleep(program->time_to_sleep * 1000);
}
// waits as long as it takes time to eat 
// only than tries to eat again. 
void	philo_thinks(t_philo *philo, t_program *program)
{
	print_save(program, philo, THINK);
	printf(" think time: %llu \n", program->time_to_die - (get_current_time(program) - philo->time_last_eaten));
	usleep(program->time_to_die /4 *1000 );
	// usleep(program->time_to_die - (get_current_time(program) - philo->time_last_eaten));
}


bool check_philo_alive(t_philo *philo, t_program *program)
{
	bool philo_alive;
	
	philo_alive = true;
	// pthread_mutex_lock(mutex_all_philos_alive)/ erst nach tester
	if(program->all_philos_alive == false)
		return(philo_alive = false);
	pthread_mutex_lock(&philo->mutex_time_last_eaten);
	if (program->time_to_die < (get_current_time(program) - philo->time_last_eaten))
	{
		philo->philo_alive = false;
		print_save(program, philo, DEAD);
		program->all_philos_alive = false;
		philo_alive = false;
	}
	pthread_mutex_unlock(&philo->mutex_time_last_eaten);
	return(philo_alive);
}

