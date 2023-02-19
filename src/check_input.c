/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:53:39 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/19 17:40:10 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	if (ft_atoi_v2(input[1]) < 1)
		return (1);
	else if (ft_atoi_v2(input[2]) < 60 || ft_atoi_v2(input[3]) < 60
			|| ft_atoi_v2(input[4]) < 60)
		return (1);
	else if (input[5] && input[5][0] == '\0')
		return (1);
	else if (input[5])
	{
		if (ft_atoi_v2(input[5]) < 0)
			return (1);
		else if (ft_atoi_v2(input[5]) == 0)
		{
			if (check_zero(input[5]))
				return (1);
			return (0);
		}
	}
	return (0);
}