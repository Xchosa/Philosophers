/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:23:57 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:26 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/philo.h"

void	*routine(void *philo_thread)
{
	t_philo *philo;
	t_program *program;

	philo = (t_philo *)philo_thread;
	program = philo->program;

	if (philo->philo_id % 2 == 0)
		usleep(4 * 1000);
		// usleep((program->time_to_eat / 2) *1000);// von micro auf mill onw func
	
	printf(" Philo %d thread has started \n", philo->philo_id);
	simulation(program, philo);
	return (NULL);
}

int    process(t_program *program)
{
    int i;
    
    i = 0;
    while(i < program->philos_and_forks)
    {
		// last par = start with the falue 
        if(pthread_create(&program->philo[i].philo_thread, NULL, routine, (void*)&program->philo[i]) != 0)
			return(perror("Failed to create thread"), 1);
		i++;
    }
	return 0;
}

// 

// s
// mirco 1/ mil	
// milli 1 k 
// macro 