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


static bool check_for_clean_nbr(int argc, char **argv)
{
	if (ft_atoi(argv[1])== -1)// atoi return -1 if it gets smth differnt
		return (false);
	if (ft_atoi(argv[2])== -1)
		return(false);
	if (ft_atoi(argv[3])== -1)
		return(false);
	if(argc == 5)
		if (ft_atoi(argv[4])== -1)
			return(false);
	return(true);
}

static void handle_one_philo(t_program *program)
{
	program->start_time = ft_get_time_millis();
	program->philos_and_forks = ft_atoi(argv[1]);
	program->time_to_die = ft_atol(argv[2]);
	print()
}

void	error_input(char *error_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	return(1); // give a paramter with it. return in the main the program 
}

bool	check_arg(int argc, char **argv)
{
	if ((argc < 4) && (argc > 5) == false)
	{
		error_input("Wrong number of arguments");
		return(false)
	}
	if (!argv[1])
	{
		error_input("Number of philos not specified");
		return (false)
	}
	// if (ft_atoi(argv[1]== 1))
	// 	handle_prin_onephio dies with timestemp after argv[2];
	if (check_for_clean_nbr(argc, argv)) == false
		return(false)
	return(true)
}
