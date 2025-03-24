/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:41:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/24 16:44:44 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while (index < n && (s1[index] != '\0' || s2[index] != '\0'))
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}


void print_func(t_program *program, t_philo *philo, char *cmd)
{
	pthread_mutex_lock(&program->time_mutex);
	if(ft_strncmp(cmd, FORK, 4))
		printf("has taken a Fork");	
	if
	pthread_mutex_unlock(&program->time_mutex);
}