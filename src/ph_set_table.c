/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_set_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:33:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/05 20:33:59 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int set_table(table_t *table, int nbr_philos, int t_die, int t_eat, int t_sleep, int nbr_meals)
{
    table->nbr_of_philos = nbr_philos;
    table->time_to_die = t_die;
    table->time_to_eat = t_eat;
    table->time_to_sleep = t_sleep;
    table->nbr_of_meals = nbr_meals;
    table->start_dinner = get_time();
    table->end_dinner = 0;
    table->philos_full = 0;
    table->philosophers = malloc(sizeof(philo_t) * nbr_philos);
    if (!(table->philosophers))
        return (1);
    pthread_mutex_init(&table->mutex_print, NULL);
    return (0);
}