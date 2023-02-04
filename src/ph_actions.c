/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/04 08:22:40 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000000) + time.tv_usec);
}

void ft_usleep(long int start, long int end)
{
    start = get_time();
    while (get_time() - start < end)
        usleep(1);
}

void print_status(char *str, philo_t *philo)
{
    long int time;
    pthread_mutex_lock(&philo->dinner_info->mutex_print);
    time = get_time();
    printf(" ---------------------------------------- \n");
    printf("|%6ld | Philo %d | %s", (time - philo->dinner_info->start_dinner) / 1000, philo->id, str);
    pthread_mutex_unlock(&philo->dinner_info->mutex_print);
}

void eating(philo_t *philo)
{
    pthread_mutex_lock((philo)->right_mutex);
    print_status("\033[32;47m🍴 Has taken R fork \033[0m |\n", philo);
    pthread_mutex_lock(&philo->left_mutex);
    print_status("\033[35;47m🍴 Has taken L fork \033[0m |\n", philo);
    print_status("\033[30;42m🍝 Is eating        \033[0m |\n", philo);
    ft_usleep(get_time(), philo->dinner_info->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->left_mutex);
    pthread_mutex_unlock((philo)->right_mutex);
}

void sleeping(philo_t *philo)
{

    print_status("\033[30;41m😴 Is sleeping      \033[0m |\n", philo);
    ft_usleep(get_time(), philo->dinner_info->time_to_sleep * 1000);
}

void thinking(philo_t *philo)
{
    print_status("\033[34;44m🤔 is thinking      \033[0m |\n", philo);
}