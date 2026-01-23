/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:55:11 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/19 12:21:03 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print %p conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int	ft_print_p_type(va_list *arguments)
{
	void			*pntr;
	unsigned long	number;
	int				len_pntr;
	int				base;
	char			*null_answer;

	pntr = va_arg(*arguments, void *);
	null_answer = "(nil)";
	if (!pntr)
	{
		if (ft_putstr_fd_ret(null_answer, 1) == -1)
			return (-1);
		return (ft_strlen(null_answer));
	}
	number = (unsigned long)pntr;
	len_pntr = 2;
	base = 16;
	if (ft_putstr_fd_ret("0x", 1) == -1)
		return (-1);
	if (ft_putnbr_base_fd((unsigned long)number, "0123456789abcdef", base, 1)
		== -1)
		return (-1);
	len_pntr += ft_len_num_base((unsigned long)number, base);
	return (len_pntr);
}
