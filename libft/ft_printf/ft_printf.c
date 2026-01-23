/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:18:10 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 17:59:31 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_type(const char *format, int *index, va_list *arguments)
{
	t_argument	arg_info;
	int			len_printed;
	int			type_print_result;

	arg_info = ft_get_arg_info(format, *index);
	len_printed = 0;
	type_print_result = 0;
	if (arg_info.type != 0)
	{
		type_print_result = ft_print_types(arguments, arg_info);
		if (type_print_result == -1)
			return (-1);
		len_printed += type_print_result;
	}
	else
	{
		if (ft_putchar_fd_ret(format[*index], 1) == -1)
			return (-1);
		len_printed++;
	}
	*index += arg_info.len;
	return (len_printed);
}

static int	ft_printf_run(const char *format, va_list *arguments)
{
	int	len_result;
	int	i;
	int	type_print_result;

	len_result = 0;
	i = 0;
	type_print_result = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			type_print_result = ft_check_type(format, &i, arguments);
			if (type_print_result == -1)
				return (-1);
			len_result += type_print_result;
		}
		else
		{
			if (ft_putchar_fd_ret(format[i], 1) == -1)
				return (-1);
			len_result++;
		}
		i++;
	}
	return (len_result);
}

/**
 * @brief Print formatted output like printf.
 * @param format Format string.
 * @return Bytes written or -1 on write error.
 */
int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		len_result;

	va_start(arguments, format);
	if (!format)
		len_result = -1;
	else
		len_result = ft_printf_run(format, &arguments);
	va_end(arguments);
	return (len_result);
}
