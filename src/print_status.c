/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:33:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/20 18:10:12 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_status(char *str, t_philo *philo)
{
	long int	time;

	pthread_mutex_lock(&philo->dinner_info->end_mtx);
	if (!philo->dinner_info->end_dinner)
	{
		pthread_mutex_lock(&philo->dinner_info->print_mtx);
		time = get_time();
		printf(" ------------------------------------------ \n");
		printf("|%6ld | Philo %03d | %s", (time
				- philo->dinner_info->start_dinner) / 1000, philo->id, str);
		pthread_mutex_unlock(&philo->dinner_info->print_mtx);
	}
	pthread_mutex_unlock(&philo->dinner_info->end_mtx);
}
