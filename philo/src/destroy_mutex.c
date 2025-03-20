/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:48 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 16:47:36 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void destro_mutex(t_program *program)
{
	pthread_mutex_destroy(&program->meal_mutex);
	pthread_mutex_destroy(&program->must_eat_mutex);
	pthread_mutex_destroy(&program->print_mutex);
	pthread_mutex_destroy(&program->death_mutex);
}