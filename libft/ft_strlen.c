/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:39:34 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/05 17:25:10 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the length of a C string (number of bytes 
 * before the first '\0').
 *
 * Counts bytes up to, but not including, the terminating null byte.
 * Behavior is undefined if @p str is NULL or not null-terminated.
 *
 * @param str Pointer to a null-terminated string.
 * @return size_t Number of bytes before '\0'.
 */
size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (counter[str] != '\0')
		counter++;
	return (counter);
}

/*int main(void)
{
    const char *cases[] = {"", "A", "Hello", "42 Network", "with\0hidden", NULL};
    for (int i = 0; cases[i]; i++) {
        size_t a = ft_strlen(cases[i]);
        size_t b = strlen(cases[i]);
        if (a != b)
            printf("Mismatch: \"%s\" ft=%zu orig=%zu\n", cases[i], a, b);
    }
    printf("ft_strlen done\n");
    return 0;
}*/