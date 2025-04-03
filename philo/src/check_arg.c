/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:43 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/03 16:30:01 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_input(char *error_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1); // give a paramter with it. return in the main the program 
}

void	check_arg(int argc, char **argv)
{
	if ((argc < 4) && (argc > 5) == false)
		error_input("Wrong number of arguments");
	if (!argv[1])
		error_input("Number of philos not specified");
	// if (argv[1] == 0)
	// 	single_philo_dies(argv[1])
}
