/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:28:38 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/07 17:41:58 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate a substring within a limited-length prefix of a C string.
 *
 * Searches for the first occurrence of the NUL-terminated @p lit_str within
 * the first @p num characters of @p big_str. Characters after @p num are not
 * inspected. If @p lit_str is empty, @p big_str is returned.
 *
 * @param big_str Pointer to the haystack (NUL-terminated).
 * @param lit_str Pointer to the needle (NUL-terminated).
 * @param num     Maximum number of characters of @p big_str to search.
 * @return char*  Pointer to the beginning of the match in @p big_str, 
 * or NULL if not found.
 */
char	*ft_strnstr(const char *big_str, const char *lit_str, size_t num)
{
	size_t	i;
	size_t	len_lit;

	if (*lit_str == '\0')
		return ((char *)big_str);
	i = 0;
	len_lit = ft_strlen(lit_str);
	while (i < num && big_str[i] != '\0')
	{
		if (big_str[i] == lit_str[0])
		{
			if (len_lit <= num - i
				&& !ft_strncmp(big_str + i, lit_str, len_lit))
				return ((char *)(big_str + i));
		}
		i++;
	}
	return (NULL);
}

/*static void run_case(const char *big, const char *lit, size_t len) {
    const char *a = ft_strnstr(big, lit, len);
    const char *b = strnstr(big, lit, len);
    long off_a = a ? (long)(a - big) : -1;
    long off_b = b ? (long)(b - big) : -1;
    if (off_a != off_b) {
        printf("Mismatch: big=\"%s\" lit=\"%s\"len=%zu 
			off_ft=%ld off_orig=%ld\n",
               big, lit, len, off_a, off_b);
    }
}

int main(void) {
    run_case("foo bar baz", "bar", 11);   // found
    run_case("foo bar baz", "bar", 3);    // cutoff before match
    run_case("hello", "", 5);             // empty needle
    run_case("aaaaa", "aaab", 5);         // partial overlaps
    run_case("abc", "abcd", 4);           // needle longer than haystack
    run_case("", "", 0);                  // len=0, empty needle -> big
    printf("ft_strnstr done\n");
    return 0;
}*/
