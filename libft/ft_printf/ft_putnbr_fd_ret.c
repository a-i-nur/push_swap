/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ret.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:46:15 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 17:56:50 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write signed int to fd and return status.
 * @param n Number to print.
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int	ft_putnbr_fd_ret(int n, int fd)
{
	if (n == -2147483648)
	{
		if (ft_putstr_fd_ret("-2147483648", fd) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar_fd_ret('-', fd) == -1)
				return (-1);
			n *= -1;
		}
		if (n >= 10)
		{
			if (ft_putnbr_fd_ret((n / 10), fd) == -1)
				return (-1);
		}
		if (ft_putchar_fd_ret(n % 10 + '0', fd) == -1)
			return (-1);
	}
	return (1);
}
