/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:56:28 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:08:47 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends a C string to a sized buffer like BSD strlcat.
 *
 * Appends src_str to dst_str of total size size_dst. Guarantees NUL-termination
 * if size_dst > 0 and size_dst > initial length of dst. Returns the length
 * it tried to create: initial_len(dst) + len(src).
 *
 * @param dst_str Destination buffer containing initial C string.
 * @param src_str Source C string to append.
 * @param size_dst Total size of destination buffer.
 * @return size_t initial_len(dst) + len(src).
 */
size_t	ft_strlcat(char *dst_str, const char *src_str, size_t size_dst)
{
	size_t	len_dst;
	size_t	len_str;
	size_t	i;
	size_t	j;

	len_dst = 0;
	while (len_dst < size_dst && dst_str[len_dst] != 0)
		len_dst++;
	len_str = ft_strlen(src_str);
	if (size_dst == len_dst)
		return (size_dst + len_str);
	i = 0;
	j = len_dst;
	while (j < size_dst - 1 && i < len_str)
	{
		dst_str[j] = src_str[i];
		j++;
		i++;
	}
	dst_str[j] = '\0';
	return (len_dst + len_str);
}

/*static void fill(char *p, size_t n, int v){ memset(p, v, n); }

int main(void)
{
    const char *srcs[] = {"", "A", "Hello", "ExtremelyLongString", NULL};
    char a[32], b[32];

    for (size_t n = 0; n <= sizeof(a); n += 5) {
        for (int i = 0; srcs[i]; i++) {
            fill(a, sizeof(a), 0); fill(b, sizeof(b), 0);
            strcpy(a, "42"); strcpy(b, "42");
            size_t ra = ft_strlcat(a, srcs[i], n);
            size_t rb = strlcat(b, srcs[i], n);
            if (ra != rb || memcmp(a, b, sizeof(a)) != 0)
                printf("Mismatch n=%zu src=\"%s\" ra=%zu rb=%zu\n", 
				n, srcs[i], ra, rb);
        }
    }
    printf("ft_strlcat done\n");
    return 0;
}

// cc ft_strlcat.c libft.a -lbsd && ./a.out*/