/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:18:05 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/10 12:43:46 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is printable, including space.
 *
 * Equivalent behavior to the `isprint()` function for ASCII inputs.
 *
 * @param symbol Integer representing the character.
 * @return 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int symbol)
{
	if (symbol >= 32 && symbol <= 126)
		return (1);
	return (0);
}

/*int main(void)
{
    for (int c = -128; c <= 255; c++)
    {
        if (ft_isprint(c) != (isprint(c) != 0))
            printf("Mismatch for %d ('%c'): ft=%d, orig=%d\n",
                c, (char)c, ft_isprint(c), isprint(c) != 0);
    }
    printf("ft_isprint test completed\n");
    return 0;
}*/