/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:36:55 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/19 18:23:34 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	end_dinner(table_t *table)
{
	int	i;
	
    i = -1;
	while (++i < table->nbr_of_philos)
		pthread_mutex_destroy(&table->philosophers[i].left_mutex);
	pthread_mutex_destroy(&table->end_mtx);
	pthread_mutex_destroy(&table->is_dead_mtx);
	pthread_mutex_destroy(&table->is_full_mtx);
	pthread_mutex_destroy(&table->print_mtx);
	free(table->philosophers);
}