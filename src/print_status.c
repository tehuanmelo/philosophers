/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:33:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/14 22:31:35 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void print_status(char *str, philo_t *philo)
{
    long int time;
    
    if (!philo->dinner_info->end_dinner)
    {
        pthread_mutex_lock(&philo->dinner_info->print_mtx);
        time = get_time(philo->dinner_info);
        printf(" ------------------------------------------ \n");
        printf("|%6ld | Philo %03d | %s", (time - philo->dinner_info->start_dinner) / 1000, philo->id, str);
        pthread_mutex_unlock(&philo->dinner_info->print_mtx);
        
    }
}