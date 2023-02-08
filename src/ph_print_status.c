/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:33:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/08 22:15:53 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void print_status(char *str, philo_t *philo)
{
    long int time;
    
    time = get_time();
    pthread_mutex_lock(&philo->dinner_info->print_mtx);
    printf(" ---------------------------------------- \n");
    printf("|%6ld | Philo %03d | %s", (time - philo->dinner_info->start_dinner) / 1000, philo->id, str);
    pthread_mutex_unlock(&philo->dinner_info->print_mtx);
}