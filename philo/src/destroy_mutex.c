/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:48 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/20 11:16:57 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    dextroy_threat_mutex(t_program *program)
{
	pthread_mutex_destroy(&program->print_mutex);

    int i;
    i = 0;
    while(i < program->philos_and_forks)
    {
        pthread_mutex_destroy(&program->forks[i]);
        i++;
    }
	// slepp function
	pthread_mutex_destroy(&program->print_mutex);
}

void	free_everything(t_program *program)
{
	int i;

	i = 0;
	while(i < program->philos_and_forks)
	{
		// free(&program->philo[i]);
		i++;
	}
}
