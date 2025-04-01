/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:41:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/01 11:33:36 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	print_save(t_program *program, t_philo *philo, char *message)
{
	pthread_mutex_lock(&program->mutex_print);
	if (program->all_philos_alive == true)
		printf(" %lu %d %s \n", get_current_time(program),
			philo->philo_id, message);
	pthread_mutex_unlock(&program->mutex_print);
}
