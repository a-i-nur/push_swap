/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:24:26 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:35:05 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write a string followed by a newline to a file descriptor.
 *
 * Writes the NUL-terminated string @p s to file descriptor @p fd, 
 * then writes a
 * newline character '\\n'. The NUL byte is not written. If @p s is NULL,
 * only the newline is written.
 *
 * @param s NUL-terminated string to write.
 * @param fd File descriptor to write to.
 */
void	ft_putendl_fd(char *s, int fd)
{
	char	new_line;

	if (!s)
		return ;
	new_line = '\n';
	ft_putstr_fd(s, fd);
	ft_putchar_fd(new_line, fd);
}
