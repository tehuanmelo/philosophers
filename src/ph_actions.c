/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/05 15:38:20 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void should_eat(philo_t *philo)
{
    // printf("Philo %d - Number of meals = %d\n", philo->id, philo->meals_count);
    if ((int)philo->meals_count == (int)philo->dinner_info->nbr_of_meals)
    {
        pthread_detach(philo->thread);
        exit(0);
    }
}

void eating(philo_t *philo)
{
    while (1)
    {
        if (philo->left_fork == 0)
        {
            // should_eat(philo);
            pthread_mutex_lock(&philo->left_mutex);
            philo->left_fork = 1;
            print_status("\033[30;47m🍴 Has taken a fork \033[0m |\n", philo);
            pthread_mutex_lock((philo)->right_mutex);
            *philo->right_fork = 1;
            print_status("\033[31;47m🍴 Has taken a fork \033[0m |\n", philo);
            print_status("\033[30;42m🍝 Is eating        \033[0m |\n", philo);
            ft_usleep(get_time(), philo->dinner_info->time_to_eat * 1000);
            philo->meals_count++;
            philo->left_fork = 0;
            *philo->right_fork = 0;
            pthread_mutex_unlock(&philo->left_mutex);
            pthread_mutex_unlock((philo)->right_mutex);
            break;
        }
        else    
            usleep(150);
    }
}

void sleeping(philo_t *philo)
{

    print_status("\033[30;41m😴 Is sleeping      \033[0m |\n", philo);
    ft_usleep(get_time(), philo->dinner_info->time_to_sleep * 1000);
}

void thinking(philo_t *philo)
{
    print_status("\033[37;44m🤔 is thinking      \033[0m |\n", philo);
}