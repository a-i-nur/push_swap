/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:56:05 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 16:16:53 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print unsigned long in given base to fd.
 * @param n Number to print.
 * @param digits_base Digits string for the base.
 * @param base Numerical base (>=2).
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int	ft_putnbr_base_fd(unsigned long n, char *digits_base, int base, int fd)
{
	if (n == 0)
	{
		if (ft_putchar_fd_ret('0', fd) == -1)
			return (-1);
		return (1);
	}
	if (n >= (unsigned long)base)
	{
		if (ft_putnbr_base_fd((n / base), digits_base, base, fd) == -1)
			return (-1);
	}
	if (ft_putchar_fd_ret(digits_base[n % base], fd) == -1)
		return (-1);
	return (1);
}
