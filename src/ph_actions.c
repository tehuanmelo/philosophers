/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/01 14:16:58 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void eating(philo_t *philo)
{
    while (1)
    {
        if (*philo->right_fork == 0 && philo->left_fork == 0)
        {
            pthread_mutex_lock(&philo->mutex_fork);
            philo->left_fork = 1;
            *(philo)->right_fork = 1;
            printf("\033[30;42mPhilo %d is eating\033[0m\n", philo->id);
            usleep(philo->dinner_info->time_to_eat * 1000000);
            philo->left_fork = 0;
            *(philo)->right_fork = 0;
            pthread_mutex_unlock(&philo->mutex_fork);
            
        break;
        }
    }
}

void sleeping(philo_t *philo)
{
    
    printf("\033[30;41mPhilo %d is sleeping\033[0m\n", philo->id);
    usleep(philo->dinner_info->time_to_eat * 1000000);
}