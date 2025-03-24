/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/24 16:27:02 by poverbec         ###   ########.fr       */
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


// every fork is a thread
// every fork can be used // needs to be the same philo
typedef struct s_forks
{
	pthread_mutex_t		fork_mutex;
	bool				fork_bool; // false free // true taken 
	int					used_by; // philo id or 0 if free;
}	t_forks;


typedef struct s_philo
{
    pthread_t			philo_thread;
    int             	philo_id;
	bool				philo_alive;
    uint_fast64_t   	time_last_eaten;
	t_forks				*left_fork;
	t_forks				*right_fork;
	uint_fast64_t   	taken_meals;
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
    uint_fast64_t   nbr_of_times_philo_must_eat;
    bool            philo_died;
	
	
	pthread_mutex_t	print_mutex;
	
	pthread_mutex_t	time_mutex;
	
	t_forks			forks[MAX_THREADS];	
	t_philo			philo[MAX_THREADS];

}	t_program;


// check input
void	check_arg(int argc, char **argv);
void	error_input(char *error_msg);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);

void    print_program_struct(t_program *program);

void	init_programm(t_program *program, char **argv, int argc);
void	init_forks(t_program *program);

// created threads for each philo 
// no need to malloc
void			init_philos(t_program *program);
uint_fast64_t 	ft_get_time_millis(void);
uint_fast64_t	get_current_time(t_program *program);
uint_fast64_t	lifespan(t_program *program, t_philo *philo);
void 			deathcheck(t_philo *philo, t_program *program);

void	*routine(void *philo_thread);
int     process(t_program *program);
void	philo_eats_right_first(t_philo *philo, t_program *program);
void 	philo_eats_left_first(t_philo *philo, t_program *program);

void	monitor(t_program *program);
void	simulation(t_program *program, t_philo *philo);
void	philo_sleeps(t_philo *philo, t_program *program);
void	philo_eats(t_philo *philo, t_program *program);
void	philo_thinks(t_philo *philo, t_program *program);

// clean_up
void    join_threats(t_program *program);
void    dextroy_threat_mutex(t_program *program);

// 
void	free_everything(t_program *program);
#endif