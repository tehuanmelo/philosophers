/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:01:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/20 18:08:59 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner_info->is_dead_mtx);
	if ((get_time() - philo->last_meal_time) >= (philo->dinner_info->time_to_die
			* 1000))
	{
		print_status("\033[37;41m😵 is dead          \033[0m |\n", philo);
		pthread_mutex_lock(&philo->dinner_info->end_mtx);
		philo->dinner_info->end_dinner = 1;
		pthread_mutex_unlock(&philo->dinner_info->end_mtx);
		pthread_mutex_unlock(&philo->dinner_info->is_dead_mtx);
		return (1);
	}
	pthread_mutex_unlock(&philo->dinner_info->is_dead_mtx);
	return (0);
}

int	if_philo_full_break(t_table *table, int philo)
{
	pthread_mutex_lock(&table->is_full_mtx);
	if (table->nbr_of_meals > 0
		&& (table->philosophers[philo].meals_count >= table->nbr_of_meals))
	{
		pthread_mutex_unlock(&table->is_full_mtx);
		return (1);
	}
	pthread_mutex_unlock(&table->is_full_mtx);
	return (0);
}

int	is_dinner_finished(t_table *table)
{
	pthread_mutex_lock(&table->end_mtx);
	if (table->end_dinner)
	{
		pthread_mutex_unlock(&table->end_mtx);
		return (1);
	}
	pthread_mutex_unlock(&table->end_mtx);
	return (0);
}

void	check_death(t_table *table)
{
	int	i;

	while (1)
	{
		if (is_dinner_finished(table))
			break ;
		i = -1;
		while ((++i < table->nbr_of_philos))
		{
			if (if_philo_full_break(table, i))
				break ;
			if (is_philo_dead(&table->philosophers[i]))
				break ;
			if (is_dinner_finished(table))
				break ;
		}
	}
}
