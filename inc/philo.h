/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:33:24 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/01/31 20:03:17 by tde-melo         ###   ########.fr       */
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


typedef struct      table_s
{
    int             nbr_of_philos;
    int             nbr_of_forks;
    int             time_to_eat;
    int             time_to_die;
    int             time_to_sleep;
    int             nbr_of_meals;
    pthread_mutex_t mutex_fork;

    

}               table_t;

typedef struct      philo_s
{
    int             id;
    int             rigth_fork;
    int             *left_fork;
    int             nb_of_meals;
    table_t         *dinner_info;
    pthread_t       thread;
}                   philo_t;

int	    ft_atoi_v2(const char *str);
void    eating(philo_t *philo);
void    sleeping(philo_t *philo);

# endif