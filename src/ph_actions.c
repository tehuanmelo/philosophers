/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:40:13 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/03 00:39:47 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000000) + time.tv_usec);
}

void	ft_usleep(long int end)
{
	long int	start;

	start = get_time();
	while (get_time() - start < end)
		usleep(1);
}

void print_status(char *str, philo_t *philo)
{
    long int time;
    pthread_mutex_lock(&philo->dinner_info->mutex_print);
    time = get_time();
    printf("%6ld Philo %d %s", (time - philo->dinner_info->start_dinner) / 1000, philo->id, str);
    pthread_mutex_unlock(&philo->dinner_info->mutex_print);
}

void eating(philo_t *philo)
{
        if (*(philo)->right_fork == 0 && philo->left_fork == 0)
        {
            pthread_mutex_lock(&philo->mutex_fork);
            *(philo)->right_fork = 1;
            print_status("\033[32;47m🍴 Has taken a fork \033[0m\n", philo);
            philo->left_fork = 1;
            print_status("\033[35;47m🍴 Has taken a fork \033[0m\n", philo);
            print_status("\033[30;42m🍝 Is eating        \033[0m\n", philo);
            ft_usleep(philo->dinner_info->time_to_eat * 1000000);
            *(philo)->right_fork = 0;
            philo->left_fork = 0;
            pthread_mutex_unlock(&philo->mutex_fork);
            usleep(150);
        }
}

void sleeping(philo_t *philo)
{
    
    print_status("\033[30;41m😴 Is sleeping      \033[0m\n", philo);
    ft_usleep(philo->dinner_info->time_to_sleep * 1000000);
    usleep(150);
}

void thinking(philo_t *philo)
{
    
    print_status("\033[34;43mis thinking\033[0m\n", philo);
    ft_usleep(philo->dinner_info->time_to_sleep * 1000000);
}