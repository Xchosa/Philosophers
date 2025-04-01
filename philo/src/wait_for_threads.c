/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:57:28 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/01 10:56:25 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    wait_for_all_threads(t_program *program)
{
    int i;

    i = 0;
    while (i < program->philos_and_forks)
    {
        pthread_join(program->philo[i].philo_thread, NULL);
        i++;
    }
}
