/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:01:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 17:09:15 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int is_philo_dead(philo_t *philo)
{
    pthread_mutex_lock(&philo->dinner_info->is_dead_mtx);
    if (philo->last_meal_time && (get_time() - philo->last_meal_time) >= (philo->dinner_info->time_to_die * 1000))
    {
        pthread_mutex_unlock(&philo->dinner_info->is_dead_mtx);
        return (1);
    }
    pthread_mutex_unlock(&philo->dinner_info->is_dead_mtx);
    return (0);
}

void check_death(table_t *table)
{
    while (!table->end_dinner)
    {
        int i = -1;
        while (!table->end_dinner && (++i < table->nbr_of_philos))
        {
            if (is_philo_dead(&table->philosophers[i]))
            {
                if (table->nbr_of_meals && (table->philosophers[i].meals_count == table->nbr_of_meals))
                    break;
                pthread_mutex_lock(&table->end_mtx);
                table->end_dinner = 1;
                pthread_mutex_unlock(&table->end_mtx);
                print_status("\033[37;41m😵 is dead          \033[0m |\n", &table->philosophers[i]);
                break;
            }
        }
    }
}