/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:07 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/02/03 19:05:09 by tde-melo         ###   ########.fr       */
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

    set_table(&table, 5, 800, 200, 100);
    create_philos(&table);
    call_philos(table.philosophers);
    return (0);
}