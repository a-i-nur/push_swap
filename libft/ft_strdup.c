/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:58:12 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:24:31 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicate a C string.
 *
 * Allocates enough memory to copy @p str including the terminating NUL,
 * then returns a pointer to the new string. 
 * Returns NULL on allocation failure.
 *
 * @param str Source NUL-terminated string.
 * @return char* Newly allocated duplicate, or NULL.
 */
char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	len_str;
	size_t	i;

	len_str = ft_strlen(str);
	duplicate = (char *)malloc((len_str + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

//int main()
//{
//	char *dupstr1, *dupstr2;
//	dupstr1 = ft_strdup("hello");
//	if (dupstr1 == NULL)
//    {
//        printf("ft_strdup failed\n");
//    }
//	else
//	{
//		printf("my f: dupstr = %s\n", dupstr1);
//		free(dupstr1);
//	}
//	dupstr2 = ft_strdup("hello");
//	if (dupstr2 == NULL)
//    {
//        printf("strdup failed\n");
//    }
//	else
//	{
//		printf("orig: dupstr = %s\n", dupstr2);
//		free(dupstr2);
//	}
//	return (0);
//}