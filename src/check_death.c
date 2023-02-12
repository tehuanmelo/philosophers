/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:01:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 19:18:27 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void check_death(table_t *table)
{
    while (!table->end_dinner)
    {
        int i = -1;
        while (!table->end_dinner && (++i < table->nbr_of_philos))
        {
            if (table->nbr_of_meals && (table->philosophers[i].meals_count == table->nbr_of_meals))
                break;
            if (is_philo_dead(&table->philosophers[i]))
                break;
        }
    }
}