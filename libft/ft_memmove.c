/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:07:34 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/05 18:00:13 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies bytes between possibly overlapping memory areas safely.
 *
 * Copies @p num_bytes from @p src_mem to @p dst_mem. Handles overlap by
 * choosing copy direction: forward if dst < src, backward otherwise.
 *
 * @param dst_mem Destination buffer.
 * @param src_mem Source buffer.
 * @param num_bytes Number of bytes to copy.
 * @return void* Original @p dst_mem.
 */
void	*ft_memmove(void *dst_mem, const void *src_mem, size_t num_bytes)
{
	const unsigned char	*src_tmp;
	unsigned char		*dst_tmp;
	size_t				i;

	src_tmp = (const unsigned char *)src_mem;
	dst_tmp = (unsigned char *)dst_mem;
	i = 0;
	if (!dst_mem && !src_mem)
		return (NULL);
	if (dst_mem == src_mem || num_bytes == 0)
		return (dst_mem);
	if (dst_tmp < src_tmp)
	{
		while (i++ < num_bytes)
			dst_tmp[i - 1] = src_tmp[i - 1];
	}
	else
	{
		i = num_bytes;
		while (i-- > 0)
			dst_tmp[i] = src_tmp[i];
	}
	return (dst_mem);
}

/*static void fill_seq(unsigned char *p, size_t n) {
    for (size_t i = 0; i < n; i++) p[i] = (unsigned char)(i & 0xFF);
}

int main(void)
{
    unsigned char a[64], b[64];

    // non-overlapping
    fill_seq(a, sizeof(a));
    fill_seq(b, sizeof(b));
    for (size_t n = 0; n <= 40; n += 7) {
        unsigned char r1[64], r2[64];
        memcpy(r1, a, sizeof(a));
        memcpy(r2, b, sizeof(b));
        memmove(r1 + 5, a + 10, n);
        ft_memmove(r2 + 5, b + 10, n);
        if (memcmp(r1, r2, sizeof(r1)) != 0)
            printf("Non-overlap mismatch n=%zu\n", n);
    }

    // overlapping forward (dst < src): safe
    unsigned char x1[32], x2[32];
    fill_seq(x1, sizeof(x1));
    memcpy(x2, x1, sizeof(x1));
    memmove(x1 + 2, x1, 16);
    ft_memmove(x2 + 2, x2, 16);
    if (memcmp(x1, x2, sizeof(x1)) != 0) printf("Overlap fwd mismatch\n");

    // overlapping backward (dst > src): safe
    fill_seq(x1, sizeof(x1));
    memcpy(x2, x1, sizeof(x1));
    memmove(x1, x1 + 2, 16);
    ft_memmove(x2, x2 + 2, 16);
    if (memcmp(x1, x2, sizeof(x1)) != 0) printf("Overlap back mismatch\n");

    printf("ft_memmove done\n");
    return 0;
}*/