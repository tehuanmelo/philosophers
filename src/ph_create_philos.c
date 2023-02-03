/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:35:29 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/02 12:35:45 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void create_philos(table_t *table)
{
    int i;

    i = -1;
    while (++i < table->nbr_of_philos)
    {
        table->philosophers[i].id = i + 1;
        table->philosophers[i].left_fork = 0;
        if (i == 0)
            table->philosophers[i].right_fork = &table->philosophers[table->nbr_of_philos - 1].left_fork;
        else
            table->philosophers[i].right_fork = &table->philosophers[i - 1].left_fork;
        table->philosophers[i].dinner_info = table;
        table->philosophers[i].meals_count = 0;
        pthread_mutex_init(&table->philosophers[i].mutex_fork, NULL);
    }
}