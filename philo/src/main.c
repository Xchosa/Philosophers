/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:25:13 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 16:49:16 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


int main(int argc, char **argv)
{
	t_program   program;

    check_arg(argc, argv);
    init_programm(&program, argv, argc); // pthread_mutex_init(&mutex, Null)
	init_philo(&program);
    // pthread_create();
        //pthread_mutex_lock();
        // operation
        // pthread_mutex_unlock()
	// pthread_join(&mutex)
	dextroy_mutex(&program);
   // pthread_mutex_destroy(&mutex);
}

init_philo
// can not pick up fork at the same time
//pick_up_fork
// only available forks
// no philo should try eating 
// eat think slepp 


// Initialization: The program starts by checking the input arguments and initializing the data structures.
// Philosopher Creation: It creates philosopher threads and starts their routines.
// Monitoring: A monitor thread checks the status of philosophers to detect if any philosopher has died or if all philosophers are full.
// Joining Threads: The main thread waits for all philosopher threads to finish.
// Cleanup: Finally, it cleans up resources like mutexes.

