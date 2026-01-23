/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:43:32 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:19:37 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two C strings up to a maximum number of bytes.
 *
 * Compares @p str1 and @p str2 lexicographically as sequences of unsigned char,
 * but examines at most @p num bytes. Comparison stops at the first difference,
 * at a NUL byte, or after @p num bytes. If @p num is 0, the result is 0.
 *
 * @param str1 First NUL-terminated C string.
 * @param str2 Second NUL-terminated C string.
 * @param num  Maximum number of bytes to compare.
 * @return int <0 if str1<str2, 0 if equal within @p num, >0 if str1>str2.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	const unsigned char	*strng1;
	const unsigned char	*strng2;
	size_t				i;

	strng1 = (const unsigned char *)str1;
	strng2 = (const unsigned char *)str2;
	i = 0;
	while (i < num)
	{
		if (strng1[i] != strng2[i] || strng1[i] == '\0' || strng2[i] == '\0')
			return (strng1[i] - strng2[i]);
		i++;
	}
	return (0);
}

/*static void run_case(const char *s1, const char *s2, size_t n) {
    int a = ft_strncmp(s1, s2, n);
    int b = strncmp(s1, s2, n);
    int sa = (a > 0) - (a < 0);
    int sb = (b > 0) - (b < 0);
    if (sa != sb) {
        printf("Mismatch: \"%s\" vs \"%s\" n=%zu  
		ft=%d orig=%d\n", s1, s2, n, a, b);
    }
}

int main(void) {
    run_case("abc", "abc", 0);
    run_case("abc", "abc", 2);
    run_case("abc", "abc", 3);
    run_case("abc", "abcd", 3);    // equal up to n
    run_case("abc", "abd", 3);     // differ before n
    run_case("a", "\xff", 1);      // unsigned compare
    run_case("a\0b", "a\0c", 3);   // stops at NUL
    run_case("", "", 5);
    printf("ft_strncmp done\n");
    return 0;
}*/