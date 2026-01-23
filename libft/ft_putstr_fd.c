/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:16:43 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:35:14 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write a string to a file descriptor.
 *
 * Writes the NUL-terminated string @p s to file descriptor @p fd. 
 * The NUL byte is not written. If @p s is NULL, nothing is written.
 *
 * @param s NUL-terminated string to write.
 * @param fd File descriptor to write to.
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
