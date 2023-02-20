/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:35:29 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/20 18:09:20 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_forks(t_table *table, int i)
{
	table->philosophers[i].left_fork = 0;
	if (i == 0)
	{
		table->philosophers[i].right_fork
			= &table->philosophers[table->nbr_of_philos - 1].left_fork;
		table->philosophers[i].right_mutex
			= &table->philosophers[table->nbr_of_philos - 1].left_mutex;
	}
	else
	{
		table->philosophers[i].right_fork
			= &table->philosophers[i - 1].left_fork;
		table->philosophers[i].right_mutex
			= &table->philosophers[i - 1].left_mutex;
	}
}

void	create_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_of_philos)
	{
		table->philosophers[i].id = i + 1;
		init_forks(table, i);
		table->philosophers[i].dinner_info = table;
		table->philosophers[i].meals_count = 0;
		table->philosophers[i].last_meal_time = get_time();
		pthread_mutex_init(&table->philosophers[i].left_mutex, NULL);
	}
}
