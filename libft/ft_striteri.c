/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:57:43 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:36 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each character of a string in place.
 *
 * Iterates through the NUL-terminated string @p s. For each character at
 * index @p i, calls @p f(i, &s[i]) so that @p f may modify the character in
 * place. Does nothing if @p s or @p f is NULL.
 *
 * @param s Input modifiable NUL-terminated string.
 * @param f Function pointer applied to each character
 * (receives index and pointer to character).
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
