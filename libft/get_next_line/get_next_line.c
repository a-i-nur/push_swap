/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:37:18 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/07 18:22:35 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Restore leftover text when newline ended in a previous read.
 * @param buf Persistent buffer that keeps unread tail.
 * @param line Current line accumulator.
 * @return 1 if a line is already complete, 0 to continue reading, 
 * -1 on malloc failure.
 */
int	ft_update_buf_info(t_read_buffer *buf, t_ret_line *line)
{
	if (buf->read_bytes <= 0 || buf->index_tail >= (size_t)buf->read_bytes)
	{
		buf->index_tail = 0;
		buf->f_end_line = 0;
		return (0);
	}
	if (buf->index_tail > 0)
	{
		line->size = BUFFER_SIZE + 1;
		line->res = (char *)malloc(line->size);
		if (!line->res)
			return (-1);
		while (buf->index_tail < (size_t)buf->read_bytes
			&& buf->read_text[buf->index_tail] != '\n')
		{
			line->res[line->len] = buf->read_text[buf->index_tail];
			buf->index_tail++;
			line->len++;
		}
		if (ft_check_end_line(buf, line, buf->index_tail))
			return (1);
	}
	buf->index_tail = 0;
	buf->f_end_line = 0;
	return (0);
}

/**
 * @brief Append characters from buffer into the growing line.
 * @param buf Buffer filled by read().
 * @param line Line accumulator which can be reallocated as it grows.
 * @return 1 when characters were appended, -1 if allocation fails.
 */
int	ft_create_line(t_read_buffer *buf, t_ret_line *line)
{
	size_t	i;
	size_t	read_bytes;

	i = 0;
	read_bytes = (size_t)buf->read_bytes;
	if (line->size - line->len < read_bytes + 1)
		if (ft_line_realloc(line, (line->size + read_bytes + 1) * 2) == -1)
			return (-1);
	while (i < read_bytes && buf->read_text[i] != '\n')
	{
		line->res[line->len] = buf->read_text[i];
		line->len++;
		i++;
	}
	ft_check_end_line(buf, line, i);
	return (1);
}

/**
 * @brief Prepare storage for the next chunk depending on read() result.
 * @param buf Buffer state after the latest read().
 * @param line Line accumulator.
 * @return 1 when the current state yields a line, 
 * 0 to keep reading, -1 on error.
 */
int	ft_check_read_text(t_read_buffer *buf, t_ret_line *line)
{
	if (buf->read_bytes == 0)
	{
		if (line->len > 0)
		{
			buf->f_end_line = 1;
			line->res[line->len] = '\0';
			return (1);
		}
		ft_liberator(line->res);
		buf->f_end_line = 1;
		return (1);
	}
	if (!line->res)
	{
		line->size = (size_t)buf->read_bytes + 1;
		line->res = (char *)malloc(line->size * sizeof(char));
		if (!line->res)
			return (-1);
	}
	return (ft_create_line(buf, line));
}

/**
 * @brief Return the next line from fd, keeping state between calls.
 * @param fd File descriptor to read from.
 * @return Allocated line including newline or NULL on EOF/error.
 */
char	*get_next_line(int fd)
{
	static t_read_buffer	buf;
	t_ret_line				line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_set_zero_line(&line);
	if (buf.f_end_line == 1)
		if (ft_update_buf_info(&buf, &line) == -1)
			return (NULL);
	while (buf.f_end_line != 1)
	{
		buf.read_bytes = read(fd, buf.read_text, BUFFER_SIZE);
		if (buf.read_bytes == -1 || ft_check_read_text(&buf, &line) == -1)
		{
			ft_set_zero_buf(&buf);
			ft_liberator(line.res);
			return (NULL);
		}
	}
	if (line.len < line.size)
		if (ft_line_realloc(&line, line.len + 1) == -1)
			return (NULL);
	return (line.res);
}
