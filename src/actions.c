/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/14 22:41:46 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void is_philo_full(philo_t *philo)
{
    if (philo->dinner_info->nbr_of_meals && (philo->meals_count == philo->dinner_info->nbr_of_meals))
    {
        if (++philo->dinner_info->nbr_of_philos_full == philo->dinner_info->nbr_of_philos)
        {
            pthread_mutex_lock(&philo->dinner_info->end_mtx);
            philo->dinner_info->end_dinner = 1;
            pthread_mutex_unlock(&philo->dinner_info->end_mtx);
        }
    }
}

int is_philo_dead(philo_t *philo)
{
    if ((get_time() - philo->last_meal_time) >= (philo->dinner_info->time_to_die * 1000))
    {
        print_status("\033[37;41m😵 is dead          \033[0m |\n", philo);
        pthread_mutex_lock(&philo->dinner_info->end_mtx);
        philo->dinner_info->end_dinner = 1;
        pthread_mutex_unlock(&philo->dinner_info->end_mtx);
        return (1);
    }
    return (0);
}

int eating(philo_t *philo)
{
        if (*philo->right_fork == 0 && philo->left_fork == 0)
        {
            pthread_mutex_lock(&philo->left_mutex);
            pthread_mutex_lock((philo)->right_mutex);
            philo->left_fork = 1;
            *philo->right_fork = 1;
            print_status("\033[30;47m🍴 Has taken a fork \033[0m |\n", philo);
            print_status("\033[31;47m🍴 Has taken a fork \033[0m |\n", philo);
            print_status("\033[30;42m🍝 Is eating        \033[0m |\n", philo);
            philo->last_meal_time = get_time(philo->dinner_info);
            ft_usleep(get_time(), philo->dinner_info->time_to_eat * 1000);
            philo->meals_count++;
            philo->left_fork = 0;
            *philo->right_fork = 0;
            pthread_mutex_unlock(&philo->left_mutex);
            pthread_mutex_unlock((philo)->right_mutex);
            is_philo_full(philo);
            return (1);
        }
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