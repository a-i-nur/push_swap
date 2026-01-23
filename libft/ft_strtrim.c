/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:27:49 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/10 13:01:18 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Trim characters from both ends of a string.
 *
 * Removes in-place conceptually (by returning a copy) 
 * all leading and trailing
 * characters from @p s1 that are present in @p set, returning a newly
 * allocated trimmed string. Middle characters are unchanged.
 *
 * @param s1  Source string (NUL-terminated).
 * @param set Set of characters to trim (as a string).
 * @return char* Newly allocated trimmed result, or NULL.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left_trim;
	size_t	right_trim;
	size_t	len_trim;
	char	*trim_str;

	if (!s1 || !set)
		return (NULL);
	left_trim = 0;
	while (s1[left_trim] && ft_strchr(set, s1[left_trim]))
		left_trim++;
	right_trim = ft_strlen(s1);
	if (left_trim < right_trim)
		while (right_trim > left_trim && ft_strchr(set, s1[right_trim - 1]))
			right_trim--;
	else
		return (ft_strdup(""));
	len_trim = right_trim - left_trim;
	trim_str = ft_substr(s1, left_trim, len_trim);
	return (trim_str);
}

/*int main()
{
	char *s1;
	char *set;
	char *result;
	
	s1 = "   hhhhh123h t4567tttt  ";
	set = "h t";
	result = ft_strtrim(s1, set);
	printf("result = \"%s\"\n", result);
	free(result);

	s1 = "   hhhhh  tttt  ";
	set = "h t";
	result = ft_strtrim(s1, set);
	printf("result = \"%s\"\n", result);
	free(result);

	s1 = "   hhhhh123h t4567tttt  ";
	set = "3";
	result = ft_strtrim(s1, set);
	printf("result = \"%s\"\n", result);
	free(result);
	return (0);
}*/