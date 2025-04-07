/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:49:08 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/07 11:24:09 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *str)
{
	int	isneg;
	int	i;
	int	number;

	number = 0;
	i = 0;
	isneg = 1;
	if ((str[i] >= '0') && (str[i] <= '9'))
	{
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			number = number * 10 + (str[i] - '0');
			if (str[i + 1] == '\0')
				return (number * isneg);
			else
				i++;
		}
		return (-1);
	}
	else
		return (-1);
}

long	ft_atol(const char *str)
{
	long	isneg;
	int		i;
	long	number;

	number = 0;
	i = 0;
	isneg = 1;
	if ((str[i] >= '0') && (str[i] <= '9'))
	{
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			number = number * 10 + (str[i] - '0');
			if (str[i + 1] == '\0')
				return (number * isneg);
			else
				i++;
		}
		return (-1);
	}
	else
		return (-1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
