/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_num_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:54:49 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 13:54:51 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return digits count of number in given base.
 * @param number Number to measure.
 * @param base Numerical base (>=2).
 * @return Amount of digits in that base.
 */
int	ft_len_num_base(unsigned long number, int base)
{
	int	len_number;

	if (number == 0)
		return (1);
	len_number = 0;
	while (number != 0)
	{
		number = number / base;
		len_number++;
	}
	return (len_number);
}
