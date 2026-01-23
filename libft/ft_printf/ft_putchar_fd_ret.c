/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_ret.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:40:55 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 16:04:04 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write char to fd and return bytes or -1.
 * @param c Character to print.
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int	ft_putchar_fd_ret(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}
