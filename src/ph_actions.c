/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/01/31 20:14:55 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void eating(philo_t *philo)
{
    
    if (philo->rigth_fork && *(philo)->left_fork)
    {
        pthread_mutex_lock(&philo->dinner_info->mutex_fork);
        philo->rigth_fork = 0;
        *(philo)->left_fork = 0;
        printf("\033[30;42mPhilo %d is eating\033[0m\n", philo->id);
        usleep(philo->dinner_info->time_to_eat * 1000000);
        philo->rigth_fork = 1;
        *(philo)->left_fork = 1;
        pthread_mutex_unlock(&philo->dinner_info->mutex_fork);
    }
}

void sleeping(philo_t *philo)
{
    
    printf("\033[30;41mPhilo %d is sleeping\033[0m\n", philo->id);
    usleep(philo->dinner_info->time_to_eat * 1000000);
}