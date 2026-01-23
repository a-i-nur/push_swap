/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:19:35 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:19:23 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scan a memory area for a byte value.
 *
 * Examines the first @p num_bytes of @p mem_area for the first occurrence of
 * the byte value (converted to unsigned char) @p byte.
 *
 * @param mem_area  Pointer to memory to scan.
 * @param byte      Byte value to search for (passed as int, converted 
 * to unsigned char).
 * @param num_bytes Number of bytes to examine.
 * @return void*    Pointer to the first matching byte, 
 * or NULL if not found within range.
 */
void	*ft_memchr(const void *mem_area, int byte, size_t num_bytes)
{
	const unsigned char	*mem_tmp;
	unsigned char		byte_tmp;
	size_t				i;

	mem_tmp = (const unsigned char *)mem_area;
	byte_tmp = (unsigned char)byte;
	i = 0;
	while (i < num_bytes)
	{
		if (mem_tmp[i] == byte_tmp)
			return ((void *)(mem_tmp + i));
		i++;
	}
	return (NULL);
}

/*static void run_case(const unsigned char *buf, size_t n, int c) {
    const unsigned char *a = ft_memchr(buf, c, n);
    const unsigned char *b = memchr(buf, c, n);
    long off_a = a ? (long)(a - buf) : -1;
    long off_b = b ? (long)(b - buf) : -1;
    if (off_a != off_b) {
        printf("Mismatch: c=0x%02X n=%zu off_ft=%ld off_orig=%ld\n", 
			c & 0xFF, n, off_a, off_b);
    }
}

int main(void) {
    unsigned char buf[] = {0x00, 0x7F, 0x80, 0x00, 0xFF};
    run_case(buf, sizeof buf, 0x00);   // first zero
    run_case(buf, sizeof buf, 0x80);
    run_case(buf, sizeof buf, 0xAA);   // absent
    run_case(buf, 0, 0x00);            // n == 0
    run_case((unsigned char*)"", 1, '\0'); // tiny
    printf("ft_memchr done\n");
    return 0;
}*/