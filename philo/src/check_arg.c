/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:43 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/08 11:36:49 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_for_clean_nbr(int argc, char **argv)
{
	if (ft_atoi(argv[1]) == -1)
		return (false);
	if (ft_atoi(argv[1]) > 200)
		return (false);
	if (ft_atoi(argv[2]) == -1)
		return (false);
	if (ft_atoi(argv[3]) == -1)
		return (false);
	if (ft_atoi(argv[4]) == -1)
		return (false);
	if (argc == 6)
		if (ft_atoi(argv[5]) == -1)
			return (false);
	return (true);
}

int	error_input(char *error_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	return (1);
}

bool	check_arg(int argc, char **argv)
{
	if ((argc < 5) || (argc > 6) == true)
	{
		error_input("Wrong number of arguments");
		return (false);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		error_input("Number of philos not specified");
		return (false);
	}
	if ((check_for_clean_nbr(argc, argv)) == false)
	{
		error_input("Only numerical input is valid");
		return (false);
	}
	return (true);
}
