/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:57 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:58 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Validate a single digit and update digit count.
 *
 * count is the number of non-leading digits processed.
 *
 * @param num Current character.
 * @param count Pointer to digit counter.
 * @return 1 if valid digit, 0 otherwise.
 */
static int	check_digit(char num, int *count)
{
	if (!ft_isdigit(num))
		return (0);
	if (num != '0')
		(*count)++;
	else if (*count > 0)
		(*count)++;
	return (1);
}

/**
 * @brief Check if a string is a valid integer number.
 *
 * Iterates all characters, ensures only digits (after optional sign),
 * and detects the "all zeros" case.
 *
 * @param num Input string.
 * @param all_zero_flag Output flag set to 1 when number is all zeros.
 * @return 1 if valid, 0 otherwise.
 */
int	is_valid_number(const char *num, int *all_zero_flag)
{
	int	i;
	int	sign;
	int	count;

	if (!num || !num[0] || !all_zero_flag)
		return (0);
	sign = 0;
	count = 0;
	*all_zero_flag = 0;
	if (num[0] == '+' || num[0] == '-')
		sign++;
	i = sign;
	while (num[i])
	{
		if (!check_digit(num[i], &count))
			return (0);
		i++;
	}
	if (count > 10 || i == sign)
		return (0);
	if (num[i - 1] == '0' && count == 0)
		*all_zero_flag = 1;
	return (1);
}
