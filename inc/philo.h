/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:33:24 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 23:05:17 by tehuanmelo       ###   ########.fr       */
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
    int             meals_count;
    long int        last_meal_time;
    struct table_s  *dinner_info;
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
    int             end_dinner;
    int             nbr_of_philos_full;
    long int        start_dinner;
    pthread_mutex_t print_mtx;
    pthread_mutex_t is_dead_mtx;
    pthread_mutex_t is_full_mtx;
    pthread_mutex_t end_mtx;
    philo_t         *philosophers;
}               table_t;

int         set_table(table_t *table, int ac, char **av);
void        create_philos(table_t *table);
void        init_threads(philo_t *philosophers);
void        join_threads(table_t *table);
void        *philo_routine(void *arg);

int         eating(philo_t *philo);
void        sleeping(philo_t *philo);
void        thinking(philo_t *philo);
void        is_philo_full(philo_t *philo);
int         is_philo_dead(philo_t *philo);
void        check_death(table_t *table);
void        end_dinner(table_t *table);

int	        ft_atoi_v2(const char *str);
long int    get_time();
void        ft_usleep(long int start, long int end);
void        print_status(char *str, philo_t *philo);

# endif