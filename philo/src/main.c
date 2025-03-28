/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:25:13 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/25 16:25:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


int main(int argc, char **argv)
{
	t_program   program;
    
    check_arg(argc, argv);
    init_arguments_in_programm(&program, argv, argc);
	initialise_mutex_in_program(&program);
    init_forks(&program);
    init_philos(&program);
    if (create_threads(&program) == 1)
         printf("Failed to create thread");
    wait_for_all_threads(&program);
	dextroy_thread_mutex(&program);
}



