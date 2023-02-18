/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:03:49 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/18 15:26:56 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/philo.h"

void *philo_routine(void *arg)
{
    while (((philo_t *)arg)->dinner_info->nbr_of_philos)
    {
        if(((philo_t *)arg)->dinner_info->end_dinner)
            break;
        thinking(((philo_t *)arg));
        if (((philo_t *)arg)->dinner_info->nbr_of_philos == 1)
            break;
        while (1)
        {
            if (eating(((philo_t *)arg)))
                break;
        }
        sleeping(((philo_t *)arg));
         
    }
    return (NULL);
}