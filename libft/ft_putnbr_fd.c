/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:41:51 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/07 17:40:26 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write an integer in decimal form to a file descriptor.
 *
 * Converts @p n to its decimal string representation (with a leading '-' if
 * negative) and writes it to file descriptor @p fd. No trailing newline is
 * added. Behavior matches standard printf("%d") formatting semantics except
 * no padding/width is applied.
 *
 * @param n Integer to write.
 * @param fd File descriptor to write to.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

/*int main()
{
	int n_plus = 2147483647;
	int n_minus = -2147483648;
	ft_putnbr_fd(n_plus, 1);
	printf("\n");
	ft_putnbr_fd(n_minus, 1);
	printf("\n");
	int n_plus1 = 0;
	int n_minus1 = -100;
	ft_putnbr_fd(n_plus1, 1);
	printf("\n");
	ft_putnbr_fd(n_minus1, 1);
	printf("\n");
	return (0);
}*/
