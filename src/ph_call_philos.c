/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_call_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/06 23:39:10 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void is_philo_dead(philo_t *philo)
{
    pthread_mutex_lock(&philo->dinner_info->check_death);
    if (philo->last_meal_time && ((get_time() - philo->last_meal_time) >= (philo->dinner_info->time_to_die * 1000)))
    {
        print_status("\033[37;41m😵 Is dead          \033[0m |\n", philo);
        // philo->dinner_info->end_dinner = 1;
        exit(0);
    }
    pthread_mutex_unlock(&philo->dinner_info->check_death);
    usleep(200);
}

int is_philo_full(philo_t *philo)
{
    if (philo->dinner_info->nbr_of_meals && (philo->meals_count == philo->dinner_info->nbr_of_meals))
        return 1;
    return (0);
}


void *dinner_service(void *arg)
{
    if (((philo_t *)arg)->id % 2 != 0)
    {
        thinking(((philo_t *)arg));
        usleep(250);
    }
    while (!is_philo_full(((philo_t *)arg)))
    {
        eating(((philo_t *)arg));
        sleeping(((philo_t *)arg));
        thinking(((philo_t *)arg));
        
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
        usleep(100);
        i++;
    }
    i = 0;
    while (i < philosophers->dinner_info->nbr_of_philos)
    {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }
}