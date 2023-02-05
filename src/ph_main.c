/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:07 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/05 21:33:50 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat] */


int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    table_t table;

    set_table(&table, 5, 0, 50, 50, 2);
    create_philos(&table);
    call_philos(table.philosophers);
    
    while (!table.end_dinner)
        usleep(200);
    return (0);
}