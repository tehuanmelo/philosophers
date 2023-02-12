/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_join_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 23:13:11 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void init_threads(philo_t *philosophers)
{
    int i;

    i = 0;
    while (i < philosophers->dinner_info->nbr_of_philos)
    {
        pthread_create(&philosophers[i].thread, NULL, &philo_routine, (void *)&philosophers[i]);
        usleep(250);
        i++;
    }
}

void join_threads(table_t *table)
{
	int i;

	i = -1;
	while (++i < table->nbr_of_philos)
		pthread_join(table->philosophers[i].thread, NULL);
}