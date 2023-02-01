/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:07 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/01 14:13:51 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat] */

int set_table(table_t *table, int nb_philos, int t_die, int t_eat, int t_sleep)
{
    table->nbr_of_philos = nb_philos;
    table->time_to_die = t_die;
    table->time_to_eat = t_eat;
    table->time_to_sleep = t_sleep;
    table->philosophers = malloc(sizeof(philo_t) * nb_philos);
    if (!(table->philosophers))
        return (1);
    return (0);
}

void create_philos(table_t *table)
{
    int i;

    i = -1;
    while (++i < table->nbr_of_philos)
    {
        table->philosophers[i].id = i + 1;
        table->philosophers[i].left_fork = 0;
        if (i == 0)
            table->philosophers[i].right_fork = &table->philosophers[table->nbr_of_philos - 1].left_fork;
        else
            table->philosophers[i].right_fork = &table->philosophers[i - 1].left_fork;
        table->philosophers[i].dinner_info = table;
        table->philosophers[i].meals_count = 0;
        pthread_mutex_init(&table->philosophers[i].mutex_fork, NULL);
    }
}

void *dinner_service(void *arg)
{
    while (1)
    {
        eating(((philo_t *)arg));
        sleeping(((philo_t *)arg));
        
    }
    return (NULL);
}

void call_philos(philo_t *philosophers)
{
    int i;

    i = 0;
    while (i < philosophers->dinner_info->nbr_of_philos)
    {
        pthread_create(&philosophers[i].thread, NULL, &dinner_service, (void *)&philosophers[i]);
        i++;
    }
    i = 0;
    while (i < philosophers->dinner_info->nbr_of_philos)
    {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    table_t table;

    set_table(&table, 4, 10, 2, 2);
    create_philos(&table);
    call_philos(table.philosophers);
    return (0);
}