/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:07:28 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:16:38 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two memory areas byte by byte.
 *
 * Compares the first @p num_bytes of @p area1 and @p area2 as sequences of
 * unsigned char. The result indicates the lexical ordering of 
 * the first pair of
 * differing bytes, or 0 if all compared bytes are equal. If @p num_bytes is 0,
 * the result is 0.
 *
 * @param area1     Pointer to the first memory block.
 * @param area2     Pointer to the second memory block.
 * @param num_bytes Number of bytes to compare.
 * @return int <0 if area1<area2, 0 if equal, >0 if area1>area2.
 */
int	ft_memcmp(const void *area1, const void *area2, size_t num_bytes)
{
	const unsigned char	*mem_tmp1;
	const unsigned char	*mem_tmp2;
	size_t				i;

	mem_tmp1 = (const unsigned char *)area1;
	mem_tmp2 = (const unsigned char *)area2;
	i = 0;
	while (i < num_bytes)
	{
		if (mem_tmp1[i] != mem_tmp2[i])
			return (mem_tmp1[i] - mem_tmp2[i]);
		i++;
	}
	return (0);
}

/*static void run_case(const unsigned char *a1, 
	const unsigned char *a2, size_t n, const char *label) {
    int a = ft_memcmp(a1, a2, n);
    int b = memcmp(a1, a2, n);
    int sa = (a > 0) - (a < 0);
    int sb = (b > 0) - (b < 0);
    if (sa != sb) {
        printf("Mismatch %s: n=%zu ft=%d orig=%d\n", label, n, a, b);
    }
}

int main(void) {
    unsigned char x1[] = {0x00, 0x7F, 0x80};
    unsigned char x2[] = {0x00, 0x7F, 0x81};
    unsigned char y1[] = {0xFF};
    unsigned char y2[] = {0x00};

    run_case(x1, x2, 0, "n=0");
    run_case(x1, x2, 2, "equal-first-two");
    run_case(x1, x2, 3, "diff-last");
    run_case(y1, y2, 1, "signedness");
    run_case((unsigned char*)"", (unsigned char*)"", 0, "empty");
    printf("ft_memcmp done\n");
    return 0;
}*/