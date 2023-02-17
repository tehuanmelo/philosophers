/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:03:49 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/17 14:34:13 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/philo.h"

void *philo_routine(void *arg)
{
    // If there is at least one philo and end_dinner flag is 0 keep looping
    while (((philo_t *)arg)->dinner_info->nbr_of_philos && !((philo_t *)arg)->dinner_info->end_dinner)
    {
        thinking(((philo_t *)arg));
        // If number of philos is 1 it can't eat with just one fork available
        if (((philo_t *)arg)->dinner_info->nbr_of_philos == 1)
            break;
        while (1)
        {
            // The philo will be waiting inside the loop until the forks become available to eat
            if (eating(((philo_t *)arg)))
                break;
            usleep(150);
        }
        sleeping(((philo_t *)arg));
         
    }
    return (NULL);
}