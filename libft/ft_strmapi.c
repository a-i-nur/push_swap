/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:44:14 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:32:17 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each character of a string, creating a new string.
 *
 * Iterates through the NUL-terminated string @p s. For each character at
 * index @p i, calls @p f(i, s[i]) and stores the returned character into a new
 * allocated string at the same position. 
 * The resulting string is NUL-terminated.
 * If allocation fails, returns NULL.
 *
 * @param s Input NUL-terminated string.
 * @param f Function pointer to apply to each character
 * (receives index and character).
 * @return char* Newly allocated transformed string, or NULL on failure.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_result;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str_result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str_result)
		return (NULL);
	while (s[i])
	{
		str_result[i] = f(i, s[i]);
		i++;
	}
	str_result[i] = '\0';
	return (str_result);
}
