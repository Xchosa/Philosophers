




#include "../inc/philo.h"

// void	routine(void *arg)
// {
// 	t_philo *philo;
// 	t_program *program;

// 	program = philo->program;
// 	philo = (t_philo *)arg;

// 	philo->philo_id = 

// 	printf(" Philo %d thread has started", program->philo->philo_id);
// 	printf(" %d has taken a fork \n", philo->philo_id);
	
// 	return ;
// }

// int    process(t_program *program)
// {
//     int i;
    
//     i = 0;
//     while(i < program->philos_and_forks)
//     {
//         if(pthread_create(&program->philo[i].philo_thread, NULL, &routine, (void*)&program->philo[i]) != 0)
// 			perror("Failed to create thread");
// 		i++;
//     }
// }