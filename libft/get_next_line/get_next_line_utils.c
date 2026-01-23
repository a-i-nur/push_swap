/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:37:15 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/07 18:22:00 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reset buffer flags so the next read starts fresh.
 * @param buf Buffer metadata to clear.
 */
void	ft_set_zero_buf(t_read_buffer *buf)
{
	buf->index_tail = 0;
	buf->f_end_line = 0;
	buf->read_bytes = 0;
}

/**
 * @brief Free allocated string if it is not NULL.
 * @param str Pointer to release.
 */
void	ft_liberator(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

/**
 * @brief Reallocate the line buffer to the requested size.
 * @param line Line accumulator metadata.
 * @param new_size Desired capacity, including space for the terminator.
 * @return 1 on success, -1 if memory allocation fails.
 */
int	ft_line_realloc(t_ret_line *line, size_t new_size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = line->res;
	line->size = new_size;
	line->res = (char *)malloc(line->size * sizeof(char));
	if (!line->res)
	{
		ft_liberator(tmp);
		return (-1);
	}
	while (i < line->len)
	{
		line->res[i] = tmp[i];
		i++;
	}
	line->res[line->len] = '\0';
	ft_liberator(tmp);
	return (1);
}

/**
 * @brief Detect newline in buffer and finalize the line if found.
 * @param buf Buffer with the recently read characters.
 * @param line Line accumulator to update.
 * @param index Position within read_text to inspect.
 * @return 1 when newline terminator was copied, 0 otherwise.
 */
int	ft_check_end_line(t_read_buffer *buf, t_ret_line *line, int index)
{
	if (index < buf->read_bytes && buf->read_text[index] == '\n')
	{
		line->res[line->len] = '\n';
		line->len++;
		line->res[line->len] = '\0';
		buf->f_end_line = 1;
		buf->index_tail = index + 1;
		return (1);
	}
	return (0);
}

/**
 * @brief Initialize line accumulator before use.
 * @param line Structure to reset.
 */
void	ft_set_zero_line(t_ret_line *line)
{
	line->res = NULL;
	line->len = 0;
	line->size = 0;
}
