/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_ret.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:56:58 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 16:05:50 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write string to fd and return status.
 * @param s String to print (can be NULL).
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int	ft_putstr_fd_ret(char *s, int fd)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (ft_putchar_fd_ret(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (1);
}
