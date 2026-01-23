/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:55:44 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/19 12:21:19 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print %x and %X conversions.
 * @param arguments Variadic arguments list.
 * @param type Requested hex variant.
 * @return Bytes written or -1 when write fails.
 */
int	ft_print_x_type(va_list *arguments, char type)
{
	unsigned int	number;
	int				base;
	char			*digits_low;
	char			*digits_upp;
	int				res;

	number = va_arg(*arguments, unsigned int);
	base = 16;
	res = 0;
	if (number == 0)
	{
		if (ft_putchar_fd_ret('0', 1) == -1)
			return (-1);
		return (1);
	}
	digits_low = "0123456789abcdef";
	digits_upp = "0123456789ABCDEF";
	if (type == 'x')
		res = ft_putnbr_base_fd((unsigned long)number, digits_low, base, 1);
	else if (type == 'X')
		res = ft_putnbr_base_fd((unsigned long)number, digits_upp, base, 1);
	if (res == -1)
		return (-1);
	return (ft_len_num_base((unsigned long)number, base));
}
