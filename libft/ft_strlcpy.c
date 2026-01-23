/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:15:44 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:08:57 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a C string into a sized buffer like BSD strlcpy.
 *
 * Copies up to dst_size-1 bytes from @p src_str into @p dst_str,
 * NUL-terminates if dst_size > 0. Returns total length of @p src_str.
 * Safe for all inputs; no overlap handling is specified.
 *
 * @param dst_str Destination buffer.
 * @param src_str Source C string (must be NUL-terminated).
 * @param dst_size Size of destination buffer in bytes.
 * @return size_t Total length of src_str (not the number copied).
 */
size_t	ft_strlcpy(char *dst_str, const char *src_str, size_t dst_size)
{
	size_t	len_src;
	size_t	i;

	i = 0;
	len_src = ft_strlen(src_str);
	if (dst_size == 0)
		return (len_src);
	while (i < len_src && i < dst_size - 1)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	dst_str[i] = '\0';
	return (len_src);
}

/*int main(void)
{
    const char *srcs[] = {"", "A", "Hello", "Very very long text", NULL};
    char a[32], b[32];

    for (size_t n = 0; n <= sizeof(a); n += 5) {
        for (int i = 0; srcs[i]; i++) {
            memset(a, 0xAA, sizeof(a));
            memset(b, 0xAA, sizeof(b));
            size_t ra = ft_strlcpy(a, srcs[i], n);
            size_t rb = strlcpy(b, srcs[i], n);
            if (ra != rb || memcmp(a, b, sizeof(a)) != 0)
                printf("Mismatch n=%zu src=\"%s\" ra=%zu rb=%zu\n", n, 
				srcs[i], ra, rb);
        }
    }
    printf("ft_strlcpy done\n");
    return 0;
}

// cc test_strlcpy.c libft.a -lbsd && ./a.out*/