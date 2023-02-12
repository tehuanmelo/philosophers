/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_set_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:33:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/12 17:02:47 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int set_table(table_t *table, int ac, char **av)
{
    table->nbr_of_philos = ft_atoi_v2(av[1]);
    table->time_to_die = ft_atoi_v2(av[2]);
    table->time_to_eat = ft_atoi_v2(av[3]);
    table->time_to_sleep = ft_atoi_v2(av[4]);
    if (ac == 6)
        table->nbr_of_meals = ft_atoi_v2(av[5]);
    else
        table->nbr_of_meals = 0;
    table->start_dinner = get_time(table);
    table->end_dinner = 0;
    table->nbr_of_philos_full = 0;
    table->philosophers = malloc(sizeof(philo_t) * table->nbr_of_philos);
    if (!(table->philosophers))
        return (1);
    pthread_mutex_init(&table->is_full_mtx, NULL);
    pthread_mutex_init(&table->print_mtx, NULL);
    pthread_mutex_init(&table->is_dead_mtx, NULL);
    pthread_mutex_init(&table->end_mtx, NULL);
    return (0);
}