/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_call_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 17:08:17 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int is_philo_full(philo_t *philo)
{
    pthread_mutex_lock(&philo->dinner_info->is_full_mtx);
    if (philo->dinner_info->nbr_of_meals && (philo->meals_count == philo->dinner_info->nbr_of_meals))
    {
        if (++philo->dinner_info->nbr_of_philos_full == philo->dinner_info->nbr_of_philos)
        {
            pthread_mutex_unlock(&philo->dinner_info->is_full_mtx);
            pthread_mutex_lock(&philo->dinner_info->end_mtx);
            philo->dinner_info->end_dinner = 1;
            pthread_mutex_unlock(&philo->dinner_info->end_mtx);
            return 1;
        }
        pthread_mutex_lock(&philo->dinner_info->is_full_mtx);
        usleep(500);
        return (1);
    }
    pthread_mutex_unlock(&philo->dinner_info->is_full_mtx);
    return (0);
}

void *dinner_service(void *arg)
{
    while (!is_philo_full(((philo_t *)arg)))
    {
        thinking(((philo_t *)arg));
        eating(((philo_t *)arg));
        sleeping(((philo_t *)arg));
        
    }
    return (NULL);
}

void call_philos(philo_t *philosophers)
{
    int i;

    i = 0;
    while (i < philosophers->dinner_info->nbr_of_philos)
    {
        pthread_create(&philosophers[i].thread, NULL, &dinner_service, (void *)&philosophers[i]);
        usleep(250);
        i++;
    }
}