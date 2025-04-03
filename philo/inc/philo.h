/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/04/03 10:40:06 by poverbec         ###   ########.fr       */
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

# define EAT		"is eating"
# define FORK		"has taken a fork"
# define SLEEP		"is sleeping"
# define THINK 		"is thinking"
# define DEAD		"philo died"

typedef struct s_forks
{
	pthread_mutex_t		fork_mutex;
	bool				fork_bool;
}	t_forks;

typedef struct s_philo
{
    pthread_t			philo_thread;
    int					philo_id;
	bool				philo_alive;
    uint_fast64_t		time_last_eaten;
	t_forks				*left_fork;
	t_forks				*right_fork;
	uint_fast64_t		taken_meals;
	pthread_mutex_t		mutex_taken_meals;
	pthread_mutex_t		mutex_time_last_eaten;
	struct s_program	*program;
}	t_philo;

typedef struct s_program
{
	int_fast32_t	philos_and_forks;
	uint_fast64_t	time_to_die;
	uint_fast64_t	time_to_eat;
	uint_fast64_t	time_to_sleep;
	uint_fast64_t	start_time;
	uint_fast64_t	nbr_of_times_philo_must_eat;
	bool			bool_meal_limit;
	bool			all_philos_alive;
	pthread_mutex_t	mutex_start_time;
	pthread_mutex_t	mutex_meals_to_take;
	pthread_mutex_t	mutex_all_philos_alive;
	pthread_mutex_t	mutex_print;
	t_forks			forks[MAX_THREADS];	
	t_philo			philo[MAX_THREADS];

}	t_program;

// Time functions
uint_fast64_t	ft_get_time_millis(void);
uint_fast64_t	get_current_time(t_program *program);

// check input
void			check_arg(int argc, char **argv);
void			error_input(char *error_msg);
void			ft_putendl_fd(char *s, int fd);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);

void			print_save(t_program *program, t_philo *philo, char *message);
void			init_arguments_in_programm(t_program *program, \
				char **argv, int argc);
void			initialise_mutex_in_program(t_program *program);
void			init_forks(t_program *program);
void			init_philos(t_program *program);

void			*routine(void *philo_thread);
int				create_threads(t_program *program);
void			initalize_philo_lifetime(t_philo *philo, t_program *program);
void			philo_eats(t_philo *philo, t_program *program);
void			choose_fork_to_unlock(t_philo *philo);
void			choose_fork_to_lock(t_philo *philo);
void			fork_back_on_table(t_philo *philo);
void			update_eaten_meals_nbr_and_time(t_philo *philo, \
				t_program *program);
void			using_forks_to_eat(t_philo *philo, t_program *program);

bool			check_philo_alive(t_philo *philo, t_program *program);
bool			check_is_philo_full(t_program *program, t_philo *philo);
void			philo_sleeps(t_philo *philo, t_program *program);
void			philo_thinks(t_philo *philo, t_program *program);

// clean_up
void			wait_for_all_threads(t_program *program);
void			destroy_thread_mutex(t_program *program);
// debug
// void			print_fork_state(t_program *program, char *time);
// void			debug_log(t_program *program, t_philo *philo, char *action);
// void	print_program_struct(t_program *program);

#endif