/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:43 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/25 16:02:47 by poverbec         ###   ########.fr       */
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
	while (str[i] == (' ') || ((str[i] >= 9) && str[i] <= 13))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			isneg *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * isneg);
}

long	ft_atol(const char *str)
{
	long	isneg;
	int		i;
	long		number;

	number = 0;
	i = 0;
	isneg = 1;
	while (str[i] == (' ') || ((str[i] >= 9) && str[i] <= 13))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			isneg *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * isneg);
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

void	error_input(char *error_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1);
}


void	check_arg(int argc, char **argv)
{
	if ((argc < 4 ) && (argc > 5) == false)
		error_input("Wrong number of arguments");
	if (!argv[1])
		error_input("Number of philos not specified");
}