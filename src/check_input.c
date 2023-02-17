/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:53:39 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/17 14:15:34 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Check number verify if the number is wether a zero or not, if the number is 
zero check number iterates over the string to verify if it is a valid 
zero or an error coming from atoi. */
int	check_zero(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		while (*str == '0')
			str++;
		if (*str)
			return (1);
	}
	return (0);
}

int	check_input(char **input)
{
	while (*(++input))
	{
		if (!ft_atoi_v2(*input))
		{
			if (check_zero(*input))
				return (1);
		}
	}
	return (0);
}