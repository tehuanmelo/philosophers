/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/05 21:37:26 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void end_dinner(table_t *table)
{
    int i;

    i = -1;
    while (--i < table->nbr_of_philos)
    {
        pthread_detach(table->philosophers[i].thread);
        pthread_mutex_destroy(&table->philosophers[i].left_mutex);
        pthread_mutex_destroy(&table->philosophers[i].stop_eating);

    }
    pthread_mutex_destroy(&table->mutex_print);
    free((pthread_t *)table->philosophers);
    table->end_dinner = 1;
}

int should_not_eat(philo_t *philo)
{
    if ((int)philo->meals_count == (int)philo->dinner_info->nbr_of_meals)
    {
        if (++philo->dinner_info->philos_full == philo->dinner_info->nbr_of_philos)
            end_dinner(philo->dinner_info);
        pthread_mutex_lock(&philo->stop_eating);
        return 1;
    }
    return 0;
}

void eating(philo_t *philo)
{
    if (should_not_eat(philo))
        pthread_mutex_lock(&philo->stop_eating);
    pthread_mutex_lock(&philo->left_mutex);
    print_status("\033[30;47m🍴 Has taken a fork \033[0m |\n", philo);
    pthread_mutex_lock((philo)->right_mutex);
    print_status("\033[31;47m🍴 Has taken a fork \033[0m |\n", philo);
    print_status("\033[30;42m🍝 Is eating        \033[0m |\n", philo);
    ft_usleep(get_time(), philo->dinner_info->time_to_eat * 1000);
    philo->meals_count++;
    pthread_mutex_unlock(&philo->left_mutex);
    pthread_mutex_unlock((philo)->right_mutex);
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