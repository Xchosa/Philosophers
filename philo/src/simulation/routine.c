/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:23:57 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/26 11:37:14 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"


void	simulation(t_program *program, t_philo *philo)
{
	while(1)
	{
		philo_eats(philo, program);
		if(check_philo_alive(philo,program ) == false)
			return ;
		philo_sleeps(philo, program);
		philo_thinks(philo, program);
		if (check_is_philo_full(program, philo) == false)
			return ;
		// debug_log(program, philo, "one_round");
	}
}

void	*routine(void *philo_thread)
{
	t_philo *philo;
	t_program *program;

	philo = (t_philo *)philo_thread;
	program = philo->program;

	if ((philo->philo_id % 2 ) == 0)
	{
		// printf(" philo %d waits %lu \n", philo->philo_id, ((program->time_to_eat / 2)));
		usleep((program->time_to_eat / 2));
	}
	simulation(program, philo);
	return (NULL);
}

int    create_threads(t_program *program)
{
    int i;
    
    i = 0;
    while(i < program->philos_and_forks)
    {
        if(pthread_create(&program->philo[i].philo_thread, NULL, routine, (void*)&program->philo[i]) != 0)
			return(1);
		i++;
    }
	return 0;
}
