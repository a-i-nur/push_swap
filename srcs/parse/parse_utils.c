/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:00 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:01 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Convert string to long with int range check.
 *
 * Iterates over digits, building the number and checking overflow.
 *
 * @param num Numeric string with optional sign.
 * @param num_int_flag Output flag: set to 0 if out of int range.
 * @return Converted long (0 on error/overflow).
 */
long	ft_atol(const char *num, int *num_int_flag)
{
	int		i;
	int		sign;
	long	res;

	if (!num || !num_int_flag)
		return (0);
	*num_int_flag = 1;
	i = 0;
	res = 0;
	sign = 1;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10;
		res = res + (num[i] - '0') * sign;
		if (res > INT_MAX || res < INT_MIN)
			return (*num_int_flag = 0, 0);
		i++;
	}
	return (res);
}
