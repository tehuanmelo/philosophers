/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:01:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/17 19:15:01 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void check_death(table_t *table)
{
    while (1)
    {
        pthread_mutex_lock(&table->end_mtx);
        if (table->end_dinner)
        {
            pthread_mutex_unlock(&table->end_mtx);
            break;
        }
            pthread_mutex_unlock(&table->end_mtx);
        int i = -1;
        while ((++i < table->nbr_of_philos))
        {
            pthread_mutex_lock(&table->end_mtx);
            if (table->end_dinner)
            {
                pthread_mutex_unlock(&table->end_mtx);
                break;
            }
            pthread_mutex_unlock(&table->end_mtx);
            pthread_mutex_lock(&table->is_full_mtx);
            if (table->nbr_of_meals && (table->philosophers[i].meals_count >= table->nbr_of_meals))
            {
                pthread_mutex_unlock(&table->is_full_mtx);
                break;
            }
            pthread_mutex_unlock(&table->is_full_mtx);
            if (is_philo_dead(&table->philosophers[i]))
                break;
        }
    }
}