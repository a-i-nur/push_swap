/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:33:25 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/21 21:34:45 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_numlines(char const *s, char c, size_t len_s)
{
	size_t	num_lines;
	size_t	i;

	num_lines = 0;
	i = 0;
	while (i < len_s)
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			num_lines++;
		}
		i++;
	}
	return (num_lines);
}

static int	ft_lbrtr(char **arr_str, size_t num_line)
{
	size_t	i;

	i = 0;
	while (i < num_line)
	{
		free(arr_str[i]);
		i++;
	}
	free(arr_str);
	return (0);
}

static void	ft_copy_line(const char *str, char *str_arr, size_t str_len)
{
	size_t	i;

	i = 0;
	while (i < str_len)
	{
		str_arr[i] = *(str + i);
		i++;
	}
	str_arr[i] = '\0';
}

static int	ft_create_lines(char **arr_str, size_t len_arr,
	char const *s, char c)
{
	size_t	i;
	size_t	num_line;
	size_t	size_line;

	i = 0;
	num_line = 0;
	while (num_line < len_arr)
	{
		size_line = 0;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			size_line++;
		}
		if (size_line != 0)
		{
			arr_str[num_line] = (char *)malloc((size_line +1) * sizeof(char));
			if (!arr_str[num_line])
				return (ft_lbrtr(arr_str, num_line));
			ft_copy_line(s + i - size_line, arr_str[num_line], size_line);
			num_line++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Split a string by a delimiter into an array of strings.
 *
 * Splits @p s on delimiter character @p c into a NULL-terminated array
 * of newly allocated tokens. Consecutive delimiters produce no empty tokens
 * (i.e., they are skipped). Returns NULL on allocation failure.
 *
 * @param s Input string (NUL-terminated).
 * @param c Delimiter character.
 * @return char** NULL-terminated array of newly allocated strings, or NULL.
 */
char	**ft_split(char const *s, char c)
{
	char	**arr_str;
	size_t	len_s;
	size_t	num_lines;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	num_lines = ft_count_numlines(s, c, len_s);
	arr_str = (char **)malloc((num_lines + 1) * sizeof(char *));
	if (!arr_str)
		return (NULL);
	arr_str[num_lines] = NULL;
	if (ft_create_lines(arr_str, num_lines, s, c) == 0)
		return (NULL);
	return (arr_str);
}

/*int	main()
{
	char *s = "h    j h h hhrthr     rthrth    h";
	char c = ' ';
	char **result = ft_split(s, c);
	if (!result)
	{
		printf("result == NULL\n");
		return(0);
	}
	int i = 0;
	while (result[i])
	{
		printf("\"%s\"\n", result[i]);
		i++;
	}
	return (0);
}*/