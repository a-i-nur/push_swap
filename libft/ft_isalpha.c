/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:56:23 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/05 14:56:33 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is alphabetic (A-Z or a-z).
 *
 * This function tests whether the given integer corresponds to an
 * alphabetic ASCII character. It behaves the same way as the standard
 * `isalpha()` function from <ctype.h>.
 *
 * @param symbol Integer representing the character to check.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int symbol)
{
	if ((symbol >= 'A' && symbol <= 'Z')
		|| (symbol >= 'a' && symbol <= 'z'))
		return (1);
	return (0);
}

/*int main(void)
{
    for (int c = -128; c <= 255; c++)
    {
        if (ft_isalpha(c) != (isalpha(c) != 0))
            printf("Mismatch for %d ('%c'): ft=%d, orig=%d\n",
                c, (char)c, ft_isalpha(c), isalpha(c) != 0);
    }
    printf("ft_isalpha test completed\n");
    return 0;
}*/