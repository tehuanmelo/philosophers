/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:01:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/07 20:07:23 by tehuanmelo       ###   ########.fr       */
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
            if (is_philo_dead(&table->philosophers[i]))
            {
                table->end_dinner = 1;
                print_status("\033[37;41m😵 is dead          \033[0m |\n", &table->philosophers[i]);
                break;
            }
        }
    }
}