/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:25:13 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/03 16:28:59 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
//https://nafuka11.github.io/philosophers-visualizer/

int	main(int argc, char **argv)
{
	t_program	program;

	check_arg(argc, argv);
	// check if smth arv holds a 5.5 oder string = false  
	// return; 
	// if only one philo -> seperate function takes the time_to_die and dies after thisAND return 
	init_arguments_in_programm(&program, argv, argc);
	initialise_mutex_in_program(&program);
	init_forks(&program);
	init_philos(&program);
	if (create_threads(&program) == 1)
		printf("Failed to create thread\n");
	wait_for_all_threads(&program);
	destroy_thread_mutex(&program);
}
