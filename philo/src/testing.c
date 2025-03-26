/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:48 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/24 13:25:49 by poverbec         ###   ########.fr       */
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
        
// 		// printf("%d philo holts right fork Nr. %d", program->philo[i].philo_id, program->philo[i].right_fork);
//         // printf("%d philo holts left fork Nr. %d", program->philo[i].philo_id, program->philo[i].left_fork);
//         i++;
// 	}
// }


// how it should look
/*
0 2 has taken a fork
0 2 has taken a fork
0 2 is eating
0 4 has taken a fork
0 4 has taken a fork
0 4 is eating
1 1 has taken a fork
2 2 is sleeping
2 4 is sleeping
2 3 has taken a fork
2 3 has taken a fork
2 3 is eating
2 1 has taken a fork
2 1 is eating
2 5 has taken a fork
4 4 is thinking
4 2 is thinking
4 1 is sleeping
4 3 is sleeping
4 2 has taken a fork
4 5 has taken a fork
4 5 is eating
4 2 has taken a fork
4 2 is eating
6 5 is sleeping
6 4 has taken a fork
6 4 has taken a fork
6 4 is eating
6 3 is thinking
6 1 is thinking
6 1 has taken a fork
6 1 has taken a fork
6 1 is eating
6 3 has taken a fork
6 2 is sleeping
8 2 is thinking
8 4 is sleeping
8 3 has taken a fork
8 5 is thinking
8 1 is sleeping
8 3 is eating
8 5 has taken a fork
8 5 has taken a fork
8 5 is eating
10 4 is thinking
10 3 is sleeping
10 1 is thinking
10 2 has taken a fork
10 2 has taken a fork
10 2 is eating
10 5 is sleeping
10 4 has taken a fork
10 4 has taken a fork
10 4 is eating
10 1 has taken a fork
12 4 is sleeping
12 3 is thinking
12 2 is sleeping
12 5 is thinking
12 5 has taken a fork
12 1 has taken a fork
12 1 is eating
12 3 has taken a fork
12 3 has taken a fork
12 3 is eating
14 3 is sleeping
14 4 is thinking
14 1 is sleeping
14 5 has taken a fork
14 5 is eating
14 2 is thinking
14 2 has taken a fork
14 2 has taken a fork
14 2 is eating
16 3 is thinking
16 1 is thinking
16 2 is sleeping
16 3 has taken a fork
16 3 has taken a fork
16 5 is sleeping
16 4 has taken a fork
16 3 is eating
16 1 has taken a fork
16 1 has taken a fork
16 1 is eating
17 4 died*/