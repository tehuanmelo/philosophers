/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:03:49 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 23:04:54 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/philo.h"

void *philo_routine(void *arg)
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