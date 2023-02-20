/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:36:55 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/20 18:09:30 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	end_dinner(t_table *table)
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
