/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:55:27 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 15:54:46 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Dispatch parsed argument to the proper print helper.
 * @param arguments Variadic arguments list.
 * @param arg_info Parsed specifier info.
 * @return Bytes written or -1 when write fails.
 */
int	ft_print_types(va_list *arguments, t_argument arg_info)
{
	if (arg_info.type == '%')
	{
		if (ft_putchar_fd_ret('%', 1) == -1)
			return (-1);
		return (1);
	}
	if (arg_info.type == 'c')
		return (ft_print_c_type(arguments));
	if (arg_info.type == 'p')
		return (ft_print_p_type(arguments));
	if (arg_info.type == 's')
		return (ft_print_s_type(arguments));
	if (arg_info.type == 'd' || arg_info.type == 'i')
		return (ft_print_di_type(arguments));
	if (arg_info.type == 'u')
		return (ft_print_u_type(arguments));
	if (arg_info.type == 'x' || arg_info.type == 'X')
		return (ft_print_x_type(arguments, arg_info.type));
	return (0);
}
