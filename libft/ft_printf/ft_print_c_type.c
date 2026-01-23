/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:54:57 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 15:42:01 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print %c conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int	ft_print_c_type(va_list *arguments)
{
	char	chrctr;

	chrctr = (char)va_arg(*arguments, int);
	if (ft_putchar_fd_ret(chrctr, 1) == -1)
		return (-1);
	return (1);
}
