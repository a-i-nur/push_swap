/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:44:35 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:27:27 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Join two C strings into a newly allocated one.
 *
 * Allocates a new string of length len(@p s1)+len(@p s2) and concatenates
 * them in order. Returns NULL on allocation failure.
 *
 * @param s1 First string (NUL-terminated).
 * @param s2 Second string (NUL-terminated).
 * @return char* Newly allocated concatenation, or NULL.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined_str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	ft_memcpy(joined_str, s1, len_s1);
	ft_memcpy(joined_str + len_s1, s2, len_s2);
	joined_str[len_s1 + len_s2] = '\0';
	return (joined_str);
}
