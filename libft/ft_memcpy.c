/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:14:32 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/05 17:56:14 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies bytes from source to destination (no overlap allowed).
 *
 * Copies @p num_bytes from @p src_mem to @p dst_mem. Behavior is undefined
 * if the memory areas overlap. For overlapping regions use ft_memmove().
 *
 * @param dst_mem Destination buffer.
 * @param src_mem Source buffer.
 * @param num_bytes Number of bytes to copy.
 * @return void* Original @p dst_mem.
 */
void	*ft_memcpy(void *dst_mem, const void *src_mem, size_t num_bytes)
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
	while (i < num_bytes)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst_mem);
}

/*int main(void)
{
    unsigned char a[64], b[64];

    for (int i = 0; i < 64; i++) a[i] = (unsigned char)i;
    for (size_t n = 0; n <= 40; n += 7) {
        // non-overlapping regions
        memcpy(b, a, sizeof(a));
        memcpy(b + 5, a + 10, n);

        unsigned char c[64];
        memcpy(c, a, sizeof(a));
        ft_memcpy(c + 5, a + 10, n);

        if (memcmp(b, c, sizeof(b)) != 0)
            printf("Mismatch for n=%zu\n", n);
    }

    // Overlap check (UB zone): demonstrate it should NOT be used for overlap
    unsigned char o1[16], o2[16];
    for (int i = 0; i < 16; i++) o1[i] = o2[i] = (unsigned char)('A'+i);
    // reference using memmove
    memmove(o1 + 2, o1, 8);
    // your memcpy would be UB here; DO NOT call ft_memcpy with overlap.
    (void)o2;
    printf("ft_memcpy done\n");
    return 0;
}*/