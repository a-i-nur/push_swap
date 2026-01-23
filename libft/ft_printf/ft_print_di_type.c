/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:55:04 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 17:53:17 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print %d and %i conversions.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int	ft_print_di_type(va_list *arguments)
{
	int		number;
	int		base;
	int		len_num;
	long	num_lng;

	number = va_arg(*arguments, int);
	base = 10;
	if (ft_putnbr_fd_ret(number, 1) == -1)
		return (-1);
	len_num = 0;
	if (number < 0)
	{
		len_num++;
		num_lng = (long)number * -1;
	}
	else
		num_lng = (long)number;
	len_num += ft_len_num_base((unsigned long)num_lng, base);
	return (len_num);
}
