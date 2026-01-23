/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:55:19 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 16:04:51 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print %s conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int	ft_print_s_type(va_list *arguments)
{
	char	*str;
	char	*null_answer;

	str = va_arg(*arguments, char *);
	null_answer = "(null)";
	if (!str)
		str = null_answer;
	if (ft_putstr_fd_ret(str, 1) == -1)
		return (-1);
	return (ft_strlen(str));
}
