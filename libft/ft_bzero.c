/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:11:05 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/05 17:49:45 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * Writes zero bytes to the first @p num_bytes of @p mem_area.
 * Equivalent to `memset(mem_area, 0, num_bytes)`.
 *
 * @param mem_area Memory area to zero.
 * @param num_bytes Number of bytes to write.
 */
void	ft_bzero(void *memblock, size_t numbytes)
{
	ft_memset(memblock, 0, numbytes);
}

/*int main(void)
{
    unsigned char a[32], b[32];
    for (size_t n = 0; n <= 32; n += 5) {
        memset(a, 0xAB, sizeof(a));
        memset(b, 0xAB, sizeof(b));
        ft_bzero(a + 2, n);
        memset(b + 2, 0, n);
        if (memcmp(a, b, sizeof(a)) != 0)
            printf("Mismatch for n=%zu\n", n);
    }
    printf("ft_bzero done\n");
    return 0;
}*/