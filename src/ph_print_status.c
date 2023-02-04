/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:33:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/04 08:36:18 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void print_status(char *str, philo_t *philo)
{
    long int time;
    pthread_mutex_lock(&philo->dinner_info->mutex_print);
    time = get_time();
    printf(" ---------------------------------------- \n");
    printf("|%6ld | Philo %d | %s", (time - philo->dinner_info->start_dinner) / 1000, philo->id, str);
    pthread_mutex_unlock(&philo->dinner_info->mutex_print);
}