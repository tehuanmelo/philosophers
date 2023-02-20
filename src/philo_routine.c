/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:03:49 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/20 18:10:01 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&((t_philo *)arg)->dinner_info->end_mtx);
		if (((t_philo *)arg)->dinner_info->end_dinner)
		{
			pthread_mutex_unlock(&((t_philo *)arg)->dinner_info->end_mtx);
			break ;
		}
		pthread_mutex_unlock(&((t_philo *)arg)->dinner_info->end_mtx);
		thinking(((t_philo *)arg));
		if (((t_philo *)arg)->dinner_info->nbr_of_philos == 1
			|| ((t_philo *)arg)->dinner_info->nbr_of_meals == 0)
			break ;
		while (1)
		{
			if (check_forks(((t_philo *)arg)))
				break ;
		}
		sleeping(((t_philo *)arg));
	}
	return (NULL);
}
