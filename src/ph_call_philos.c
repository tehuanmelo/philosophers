/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_call_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 18:37:02 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"



void *dinner_service(void *arg)
{
    while (!(((philo_t *)arg)->dinner_info->end_dinner))
    {
        thinking(((philo_t *)arg));
        while (1)
        {
            if (eating(((philo_t *)arg)))
                break;
        }
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