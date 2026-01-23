/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:52:07 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:26:53 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extract a substring from a string.
 *
 * Returns a newly allocated substring of @p s that starts at index @p start
 * (0-based) and is at most @p len characters long, or an empty string if
 * @p start >= length of @p s. Never reads past the end of @p s.
 *
 * @param s   Source NUL-terminated string.
 * @param start Starting index within @p s.
 * @param len   Maximum substring length.
 * @return char* Newly allocated substring, or NULL on allocation failure.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_str;
	size_t	i;
	size_t	len_avail;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	if (start >= len_str)
		return (ft_strdup(""));
	len_avail = ft_strlen(s + start);
	if (len_avail < len)
		len = len_avail;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

//int main()
//{
//	printf("exp = \"He\", my_f = \"%s\"\n", ft_substr("Hello", 0, 2));
//	printf("exp = \"llo\", my_f = \"%s\"\n", ft_substr("Hello", 2, 10));
//	printf("exp = \"\", my_f = \"%s\"\n", ft_substr("Hello", 5, 2));
//	printf("exp = \"\", my_f = \"%s\"\n", ft_substr("", 0, 5));
//	printf("exp = \"\", my_f = \"%s\"\n", ft_substr("abc", 100, 1));
//}m