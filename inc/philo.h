/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:33:24 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/04 08:37:38 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PHILO_H
#   define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct      philo_s
{
    int             id;
    int             left_fork;
    int             *right_fork;
    struct table_s  *dinner_info;
    int             meals_count;
    pthread_t       thread;
    pthread_mutex_t *right_mutex;
    pthread_mutex_t left_mutex;
}                   philo_t;

typedef struct      table_s
{
    int             nbr_of_philos;
    int             nbr_of_forks;
    int             time_to_eat;
    int             time_to_die;
    int             time_to_sleep;
    int             nbr_of_meals;
    long int        start_dinner;
    pthread_mutex_t mutex_print;
    philo_t         *philosophers;
}               table_t;

int         set_table(table_t *table, int nb_philos, int t_die, int t_eat, int t_sleep);
void        create_philos(table_t *table);
void        call_philos(philo_t *philosophers);

void        eating(philo_t *philo);
void        sleeping(philo_t *philo);
void        thinking(philo_t *philo);

int	        ft_atoi_v2(const char *str);
long int    get_time();
void        ft_usleep(long int start, long int end);
void        print_status(char *str, philo_t *philo);

# endif