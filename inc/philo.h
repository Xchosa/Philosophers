


#ifndef PHILO_H
# define PHILO_H

# ifndef MAX_THREADS
#  define MAX_THREADS 200
# endif




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


typedef struct s_philo
{
    uint_fast64_t		time_to_die;
	uint_fast64_t		time_to_eat;
	uint_fast64_t		time_to_sleep;
    uint_fast64_t       nbr_of_times_philo_must_eat;

}   t_philo;


typedef struct s_program
{
    bool    start;
    bool    stop;
    bool    nbr; 1 free 0 occupied

}   t_program;



typdef struct s_semaphore
{
    char   chopstick[nbr]    
}


#endif