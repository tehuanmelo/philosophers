/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:33:24 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/01 14:14:33 by tehuanmelo       ###   ########.fr       */
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
    pthread_mutex_t mutex_fork;
    pthread_t       thread;
}                   philo_t;

typedef struct      table_s
{
    int             nbr_of_philos;
    int             nbr_of_forks;
    int             time_to_eat;
    int             time_to_die;
    int             time_to_sleep;
    int             nbr_of_meals;
    int             start_dinner;
    philo_t         *philosophers;
}               table_t;



int	    ft_atoi_v2(const char *str);
void    eating(philo_t *philo);
void    sleeping(philo_t *philo);

# endif