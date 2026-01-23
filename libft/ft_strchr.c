/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:21:23 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:14:25 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find the first occurrence of a character in a C string.
 *
 * Searches @p str for the first occurrence of the character (converted to
 * unsigned char) @p chrctr. The terminating '\\0' is considered part of the
 * string, so a search for '\\0' will return a pointer to the terminator.
 *
 * @param str     Pointer to a NUL-terminated C string.
 * @param chrctr  Character to locate (passed as int, 
 * converted to unsigned char).
 * @return char*  Pointer to the first occurrence within @p str, 
 * or NULL if not found.
 */
char	*ft_strchr(const char *str, int chrctr)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)chrctr)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)chrctr)
		return ((char *)str + i);
	return (NULL);
}

/*static void run_case(const char *label, const char *s, int c) {
    const char *a = ft_strchr(s, c);
    const char *b = strchr(s, c);
    long off_a = a ? (long)(a - s) : -1;
    long off_b = b ? (long)(b - s) : -1;
    if (off_a != off_b) {
        printf("Mismatch %s: c=%d off_ft=%ld off_orig=%ld\n", 
			label, c, off_a, off_b);
    }
}

int main(void) {
    char with_nul[] = { 'a', '\0', 'b', 0 };
    run_case("empty", "", 'x');
    run_case("basic", "hello", 'l');
    run_case("absent", "world", 'x');
    run_case("nul-search", "abc", '\0');
    run_case("after-nul", with_nul, 'b'); 
    run_case("high-bit", "A\x80\xFF", 0x80);
    printf("ft_strchr done\n");
    return 0;
}*/