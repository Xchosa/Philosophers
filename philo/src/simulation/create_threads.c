/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:23:57 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/07 10:54:11 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"


static void	handle_one_philo(t_philo *philo, t_program *program)
{
	usleep(program->time_to_die * 1000);
	print_save(program, philo, DEAD);
}


void	*routine(void *philo_thread)
{
	t_philo		*philo;
	t_program	*program;

	philo = (t_philo *)philo_thread;
	program = philo->program;
	initalize_philo_lifetime(philo, program);
	if (program->philos_and_forks == 1)
	{
		handle_one_philo(philo, program);
		return (NULL);
	}
	if ((philo->philo_id % 2) == 0)
		usleep((program->time_to_eat / 10));
	while (1)
	{
		if (check_philo_alive(philo, program) == false)
			return (NULL);
		philo_eats(philo, program);
		if ((check_is_philo_full(program, philo)) == false)
			return (NULL);
		philo_sleeps(philo, program);
		philo_thinks(philo, program);
	}
	return (NULL);
}

int	create_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philos_and_forks)
	{
		if (pthread_create(&program->philo[i].philo_thread, NULL,
				routine, (void*)&program->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
