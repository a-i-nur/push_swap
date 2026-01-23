/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:06:27 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/05 15:11:08 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a value is a valid ASCII code (0–127).
 *
 * Unlike the standard `isascii()` extension, this function strictly
 * returns 1 for valid ASCII values and 0 otherwise.
 *
 * @param symbol Integer to test.
 * @return 1 if the value is within ASCII range, 0 otherwise.
 */
int	ft_isascii(int symbol)
{
	if (symbol >= 0 && symbol <= 127)
		return (1);
	return (0);
}

/*int main(void)
{
    for (int c = -128; c <= 255; c++)
    {
        int ref = isascii(c) != 0;
        int mine = ft_isascii(c);

        if (mine != ref)
        {
            printf("Mismatch for %d: ft=%d, orig=%d\n",
                   c, mine, ref);
        }
    }

    printf("ft_isascii test completed\n");
    return 0;
}*/