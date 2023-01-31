/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:33:24 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/01/31 11:13:15 by tehuanmelo       ###   ########.fr       */
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


typedef struct  table_s
{
   int          nbr_of_philos;
   int          nbr_of_forks;
   int          time_to_eat;
   int          time_to_die;
   int          time_to_sleep;
   int          nbr_of_meals;
}               table_t;

typedef struct  philo_s
{
    int         id;
    pthread_t   thread;
    int         rigth_fork;
    int         *left_fork;
    table_t     *dinner_info;
}               philo_t;

int	ft_atoi_v2(const char *str);

# endif