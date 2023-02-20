/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/20 15:35:39 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void is_philo_full(philo_t *philo)
{
    pthread_mutex_lock(&philo->dinner_info->is_full_mtx);
    if (philo->dinner_info->nbr_of_meals && (++philo->meals_count == philo->dinner_info->nbr_of_meals))
    {
        if (++philo->dinner_info->nbr_of_philos_full == philo->dinner_info->nbr_of_philos)
        {
            pthread_mutex_unlock(&philo->dinner_info->is_full_mtx);
            pthread_mutex_lock(&philo->dinner_info->end_mtx);
            philo->dinner_info->end_dinner = 1;
            pthread_mutex_unlock(&philo->dinner_info->end_mtx);
            return;
        }
    }
    pthread_mutex_unlock(&philo->dinner_info->is_full_mtx);
}

void eating(philo_t *philo)
{
    print_status("\033[30;47m🍴 Has taken a fork \033[0m |\n", philo);
    print_status("\033[31;47m🍴 Has taken a fork \033[0m |\n", philo);
    print_status("\033[30;42m🍝 Is eating        \033[0m |\n", philo);
    pthread_mutex_lock(&philo->dinner_info->is_dead_mtx);
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->dinner_info->is_dead_mtx);
    ft_usleep(get_time(), philo->dinner_info->time_to_eat * 1000);
    pthread_mutex_lock(&philo->left_mutex);
    philo->left_fork = 0;
    pthread_mutex_unlock(&philo->left_mutex);
    pthread_mutex_lock(philo->right_mutex);
    *philo->right_fork = 0;
    pthread_mutex_unlock(philo->right_mutex);
    is_philo_full(philo);
}

int check_forks(philo_t *philo)
{
    pthread_mutex_lock(&philo->left_mutex);
    if (philo->left_fork == 0)
    {
        philo->left_fork = 1;
        pthread_mutex_unlock(&philo->left_mutex);
        pthread_mutex_lock(philo->right_mutex);
        if (*philo->right_fork == 0)
        {
            *philo->right_fork = 1;
            pthread_mutex_unlock(philo->right_mutex);
            eating(philo);
            return (1);
        }
        else
        {
            pthread_mutex_unlock(philo->right_mutex);
            pthread_mutex_lock(&philo->left_mutex);
            philo->left_fork = 0;
            pthread_mutex_unlock(&philo->left_mutex);
        }
    }
    else
        pthread_mutex_unlock(&philo->left_mutex);
    return (0);
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