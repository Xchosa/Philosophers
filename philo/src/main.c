/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:25:13 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/07 09:47:37 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
//https://nafuka11.github.io/philosophers-visualizer/

int	main(int argc, char **argv)
{
	t_program	program;

	if (check_arg(argc, argv) == false)
		return (1);
	init_arguments_in_programm(&program, argv, argc);
	initialise_mutex_in_program(&program);
	init_forks(&program);
	init_philos(&program);
	if (create_threads(&program) == 1)
		printf("Failed to create thread\n");
	wait_for_all_threads(&program);
	destroy_thread_mutex(&program);
}
