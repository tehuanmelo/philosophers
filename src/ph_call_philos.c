/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_call_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/05 21:33:55 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void *dinner_service(void *arg)
{
    if (((philo_t *)arg)->id % 2 != 0)
    {
        thinking(((philo_t *)arg));
        usleep(250);
    }
    while (1)
    {
        eating(((philo_t *)arg));
        sleeping(((philo_t *)arg));
        thinking(((philo_t *)arg));
        
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
        usleep(100);
        i++;
    }
    // i = 0;
    // while (i < philosophers->dinner_info->nbr_of_philos)
    // {
    //     pthread_join(philosophers[i].thread, NULL);
    //     i++;
    // }
}