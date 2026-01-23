/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:55:37 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 16:18:30 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print %u conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int	ft_print_u_type(va_list *arguments)
{
	unsigned int	number;
	int				base;
	char			*digits;

	number = va_arg(*arguments, unsigned int);
	base = 10;
	digits = "0123456789";
	if (ft_putnbr_base_fd((unsigned long)number, digits, base, 1) == -1)
		return (-1);
	return (ft_len_num_base((unsigned long)number, base));
}
