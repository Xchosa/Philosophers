/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:48 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/07 12:51:40 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// void    print_program_struct(t_program *program)
// {
// 	printf(" philo id %d \n", program->philo->philo_id);
//     printf("%llu start time \n", program->start_time);
//     printf("%d philos_and forks \n", program->philos_and_forks);
//     printf("%llu time to die\n ",program->time_to_die);
//     printf("%llu time to eat\n ",program->time_to_eat);
//     printf("%llu time to sleep\n ",program->time_to_sleep);
//     int i;
//     i = 0;
// 	while (i < program->philos_and_forks)
// 	{
// 		printf("%d id philos are living\n", program->philo[i].philo_id );
//
// 		// printf("%d philo holts right fork Nr. %d", 
// program->philo[i].philo_id, program->philo[i].right_fork);
//         // printf("%d philo holts left fork Nr. %d", 
//	program->philo[i].philo_id, program->philo[i].left_fork);
//         i++;
// 	}
// }
//
// void debug_log(t_program *program, t_philo *philo, char *action)
// {
//     pthread_mutex_lock(&program->mutex_print);
//     printf("[DEBUG] %lu ms | Philo %d | %s | Eaten: %lu |
//		 Last eaten: %lu\n", 
//         get_current_time(program), philo->philo_id, action, 
//         philo->taken_meals, philo->time_last_eaten);
//     pthread_mutex_unlock(&program->mutex_print);
// }

