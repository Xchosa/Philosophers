/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_times.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:42:46 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/03 11:11:23 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// 1sec = 1000 milliseconds
// 1 sec = 1 000 000 microseconds 
uint_fast64_t	ft_get_time_millis(void)
{
	struct timeval	time;
	uint_fast64_t	time_milisec;

	if (gettimeofday(&time, NULL) != 0)
		perror("faild to find time of the day");
	time_milisec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_milisec);
}

uint_fast64_t	get_current_time(t_program *program)
{
	return (ft_get_time_millis() - program->start_time);
}
