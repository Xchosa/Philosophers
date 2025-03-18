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
    int             philo_id;
    uint_fast64_t   time_last_eaten;
    pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	bool			philo_is_full;
	struct s_data	*data;

}	t_philo;


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
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	must_eat_mutex;
	pthread_mutex_t	forks[MAX_THREADS];
	t_philo			philos[MAX_THREADS];

}	t_program;


// check input
void	check_arg(int argc, char **argv);
void	error_input(char *error_msg);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);


void init_programm(t_program *program, char **argv, int argc);



// clean_up
void    join_threats(t_program *program);
void    dextroy_threat_mutex(t_program *program);

#endif