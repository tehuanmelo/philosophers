/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:03:49 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/19 18:03:08 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void *philo_routine(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&((philo_t *)arg)->dinner_info->end_mtx);
        if (((philo_t *)arg)->dinner_info->end_dinner)
        {
            pthread_mutex_unlock(&((philo_t *)arg)->dinner_info->end_mtx);
            break;
        }
        pthread_mutex_unlock(&((philo_t *)arg)->dinner_info->end_mtx);
        thinking(((philo_t *)arg));
        if (((philo_t *)arg)->dinner_info->nbr_of_philos == 1 || ((philo_t *)arg)->dinner_info->nbr_of_meals == 0)
            break;
        while (1)
        {
            if (check_forks(((philo_t *)arg)))
                break;
        }
        sleeping(((philo_t *)arg));
    }
    return (NULL);
}