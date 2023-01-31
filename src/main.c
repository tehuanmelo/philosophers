/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:07 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/01/31 20:15:47 by tde-melo         ###   ########.fr       */
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
    pthread_mutex_init(&table->mutex_fork, NULL);
    
    
    return (0);
}

philo_t *create_philos(table_t *table)
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

void *philo_routine(void *arg)
{
    (void)arg;
    while (1)
    {
        if (((philo_t *)arg)->dinner_info->nbr_of_philos % 2 == 0)
        {
            if (((philo_t *)arg)->id % 2 == 0)
            {
                eating(((philo_t *)arg));
                sleeping(((philo_t *)arg));
            }
            else
            {
                sleeping(((philo_t *)arg));
                eating(((philo_t *)arg));
                
            }
            
        }
        
    }
    return NULL;
}

void call_philos(philo_t *philos)
{
    int i;

    i = 0;
    while (i < philos->dinner_info->nbr_of_philos)
    {
        pthread_create(&philos[i].thread, NULL, &philo_routine, (void *)&philos[i]);
        i++;
    }
    i = 0;
    while (i < philos->dinner_info->nbr_of_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    table_t table;
    philo_t *philos;
    
    set_table(&table, 2, 10, 2, 2);
    philos = create_philos(&table);
    call_philos(philos);
    (void)philos;
    return (0);   
}