/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 16:30:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H


# include <inttypes.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef MAX_THREADS
#  define MAX_THREADS 200
# endif


typedef enum s_actions
{
    FORK,    // 0
    EATING,  // 1
    SLEEPING, // 2
    THINKING, // 3
    DIED     // 4
} t_actions;


typedef struct s_philo
{
    int             	philo_id;
    uint_fast64_t   	time_last_eaten;
    pthread_t			philo_thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_program	*program;

}	t_philo;


// bool fork = free not free

typedef struct s_program
{
	int_fast32_t	philos_and_forks;
    uint_fast64_t	time_to_die;
	uint_fast64_t	time_to_eat;
	uint_fast64_t	time_to_sleep;
    uint_fast64_t	start_time;
    int_fast32_t    nbr_of_times_philo_must_eat;
    bool            philo_died;
    bool            philo_satisfied;
    bool            start_routine;
	pthread_mutex_t	eats_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	think_mutex;
	pthread_mutex_t	must_eat_mutex;
	pthread_mutex_t	forks[MAX_THREADS];
	t_philo			philo[MAX_THREADS];

}	t_program;


// check input
void	check_arg(int argc, char **argv);
void	error_input(char *error_msg);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);

void    print_program_struct(t_program *program);

void	init_programm(t_program *program, char **argv, int argc);
void	init_fork(t_program *program);

// created threads for each philo 
// no need to malloc
void			init_philos(t_program *program);
uint_fast64_t 	ft_get_time(void);
uint_fast64_t	get_current_time(t_program *program);

void	routine();
int     process(t_program *program);

// clean_up
void    join_threats(t_program *program);
void    dextroy_threat_mutex(t_program *program);

// 
void	free_everything(t_program *program);
#endif