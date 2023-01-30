/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:07 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/01/31 00:02:51 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat] */

typedef struct philo_s
{
    pthread_t thread;
    int rigth_fork;
}philo_t;

typedef struct table_s
{
   int  nbr_of_philos;
   int  nbr_of_forks;
   int  time_to_eat;
   int  time_to_die;
   int  time_to_sleep;
   int  nbr_of_meals;
   pthread_t *philosophers;
}table_t;

int set_table(table_t *table, int nb_philos, int t_die, int t_eat, int t_sleep)
{
    table->nbr_of_philos = nb_philos;
    table->time_to_die = t_die;
    table->time_to_eat = t_eat;
    table->time_to_sleep = t_sleep;
    table->philosophers = malloc(sizeof(pthread_t) * nb_philos);
    return (0);
}

void *philo_routine(void *arg)
{
    int n = *(int *)arg;
    printf("Philo %d just sited on the table\n", ++n);
    return NULL;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    table_t table;
    set_table(&table, 2, 4, 2, 2);

    for (int i = 0; i < 5; i++)
    {
       pthread_create(&table.philosophers[i], NULL, philo_routine, (void *)&i);
       usleep(100);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(table.philosophers[i], NULL);
    }
    
    
}