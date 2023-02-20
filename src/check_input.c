/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:53:39 by tde-melo          #+#    #+#             */
/*   Updated: 2023/02/20 20:02:52 by tde-melo         ###   ########.fr       */
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
	if (ft_atoi_v2(input[1]) < 1 || ft_atoi_v2(input[2]) < 1
		|| ft_atoi_v2(input[3]) < 1 || ft_atoi_v2(input[4]) < 1)
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
