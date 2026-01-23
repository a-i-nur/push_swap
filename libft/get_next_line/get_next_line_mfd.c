/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mfd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:37:18 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/07 17:44:44 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Variant of get_next_line that keeps an independent buffer per fd.
 * @param fd File descriptor to read from.
 * @return Allocated line including newline or NULL on EOF/error.
 */
char	*get_next_line_mfd(int fd)
{
	static t_read_buffer	buf[1024];
	t_ret_line				line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_set_zero_line(&line);
	if (buf[fd].f_end_line == 1)
		if (ft_update_buf_info(&buf[fd], &line) == -1)
			return (NULL);
	while (buf[fd].f_end_line != 1)
	{
		buf[fd].read_bytes = read(fd, buf[fd].read_text, BUFFER_SIZE);
		if (buf[fd].read_bytes == -1
			|| ft_check_read_text(&buf[fd], &line) == -1)
		{
			ft_set_zero_buf(&buf[fd]);
			ft_liberator(line.res);
			return (NULL);
		}
	}
	if (line.len < line.size)
		if (ft_line_realloc(&line, line.len + 1) == -1)
			return (NULL);
	return (line.res);
}
