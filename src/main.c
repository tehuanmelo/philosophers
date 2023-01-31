/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:07 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/01/31 14:11:46 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat] */

void *philo_routine(void *arg)
{
    printf("Philo %d just sited on the table\n", ((philo_t *)arg)->id);
    return NULL;
}

philo_t *created_philos(table_t *table)
{
    int i;
    philo_t *philosophers;

    philosophers = malloc(sizeof(philo_t) * table->nbr_of_philos);
    i = 0;
    while (i < table->nbr_of_philos)
    {
        philosophers[i].id = i + 1;
        philosophers[i].dinner_info = table;
        philosophers[i].rigth_fork = 1;
        if (i == 0)
            philosophers[i].left_fork = &philosophers[table->nbr_of_philos - 1].rigth_fork;
        else
            philosophers[i].left_fork = &philosophers[i - 1].rigth_fork;
        i++;
    }
    return (philosophers);
}

int set_table(table_t *table, int nb_philos, int t_die, int t_eat, int t_sleep)
{
    table->nbr_of_philos = nb_philos;
    table->time_to_die = t_die;
    table->time_to_eat = t_eat;
    table->time_to_sleep = t_sleep;
    return (0);
}

void call_philos()
{
    
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    table_t table;
    philo_t *philos;
    
    set_table(&table, 2, 4, 2, 2);
    philos = created_philos(&table);
    (void)philos;
    return (0);   
}