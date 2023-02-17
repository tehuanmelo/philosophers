/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:01:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/17 13:48:28 by tde-melo         ###   ########.fr       */
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
            if (table->nbr_of_meals && (table->philosophers[i].meals_count >= table->nbr_of_meals))
                break;
            if (is_philo_dead(&table->philosophers[i]))
                break;
        }
    }
}