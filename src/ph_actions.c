/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/06 23:22:27 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void eating(philo_t *philo)
{
    pthread_mutex_lock(&philo->left_mutex);
    pthread_mutex_lock((philo)->right_mutex);
    is_philo_dead(philo);
    print_status("\033[30;47m🍴 Has taken a fork \033[0m |\n", philo);
    print_status("\033[31;47m🍴 Has taken a fork \033[0m |\n", philo);
    print_status("\033[30;42m🍝 Is eating        \033[0m |\n", philo);
    philo->last_meal_time = get_time();
    ft_usleep(get_time(), philo->dinner_info->time_to_eat * 1000);
    philo->meals_count++;
    pthread_mutex_unlock(&philo->left_mutex);
    pthread_mutex_unlock((philo)->right_mutex);
}

void sleeping(philo_t *philo)
{
    print_status("\033[37;45m😴 Is sleeping      \033[0m |\n", philo);
    ft_usleep(get_time(), philo->dinner_info->time_to_sleep * 1000);
}

void thinking(philo_t *philo)
{
    print_status("\033[37;44m🤔 is thinking      \033[0m |\n", philo);
}