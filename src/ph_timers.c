/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_timers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:32:57 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/08 22:15:42 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000000) + time.tv_usec);
}

void ft_usleep(long int start, long int end)
{
    while (get_time() - start < end)
        usleep(1);
}