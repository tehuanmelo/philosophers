/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:33:24 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/20 18:12:30 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				*right_fork;
	int				meals_count;
	long int		last_meal_time;
	struct s_table	*dinner_info;
	pthread_t		thread;
	pthread_mutex_t	*right_mutex;
	pthread_mutex_t	left_mutex;
}					t_philo;

typedef struct s_table
{
	int				nbr_of_philos;
	int				nbr_of_forks;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				end_dinner;
	int				nbr_of_philos_full;
	long int		start_dinner;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	is_dead_mtx;
	pthread_mutex_t	is_full_mtx;
	pthread_mutex_t	end_mtx;
	t_philo			*philosophers;
}					t_table;

int					set_table(t_table *table, int ac, char **av);
void				create_philos(t_table *table);
void				init_threads(t_philo *philosophers);
void				join_threads(t_table *table);
void				*philo_routine(void *arg);

int					check_forks(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
void				check_death(t_table *table);
void				end_dinner(t_table *table);

int					ft_atoi_v2(const char *str);
long int			get_time(void);
void				ft_usleep(long int start, long int end);
void				print_status(char *str, t_philo *philo);
int					check_input(char **input);

#endif