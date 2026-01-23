/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:49:33 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:15:05 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find the last occurrence of a character in a C string.
 *
 * Searches @p str for the final occurrence of the character (converted to
 * unsigned char) @p chrctr. The terminating '\\0' is considered part of the
 * string, so a search for '\\0' will return a pointer to the terminator.
 *
 * @param str     Pointer to a NUL-terminated C string.
 * @param chrctr  Character to locate (passed as int, 
 * converted to unsigned char).
 * @return char*  Pointer to the last occurrence within @p str, 
 * or NULL if not found.
 */
char	*ft_strrchr(const char *str, int chrctr)
{
	size_t			len;
	size_t			i;
	unsigned char	trgt;

	len = ft_strlen(str);
	trgt = (unsigned char)chrctr;
	i = len;
	while (i > 0)
	{
		if ((unsigned char)str[i] == trgt)
			return ((char *)str + i);
		i--;
	}
	if ((unsigned char)str[i] == trgt)
		return ((char *)str + i);
	return (NULL);
}

/*static void run_case(const char *label, const char *s, int c) {
    const char *a = ft_strrchr(s, c);
    const char *b = strrchr(s, c);
    long off_a = a ? (long)(a - s) : -1;
    long off_b = b ? (long)(b - s) : -1;
    if (off_a != off_b) {
        printf("Mismatch %s: c=%d off_ft=%ld off_orig=%ld\n", 
			label, c, off_a, off_b);
    }
}

int main(void) {
    run_case("empty", "", 'x');
    run_case("basic", "bananas", 'a');      // last 'a'
    run_case("absent", "world", 'x');
    run_case("nul-search", "abc", '\0');    // pointer to terminator
    run_case("dup", "mississippi", 's');    // multiple hits
    printf("ft_strrchr done\n");
    return 0;
}*/