/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:13:59 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:33:39 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write a character to a file descriptor.
 *
 * Writes the character @p c to the file descriptor @p fd using a single write
 * call. Behavior is undefined if @p fd is invalid.
 *
 * @param c Character to write.
 * @param fd File descriptor to write to.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
