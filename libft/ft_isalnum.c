/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:52:15 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/05 15:01:25 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is alphanumeric (a-z, A-Z, 0-9).
 *
 * Works like `isalnum()` from <ctype.h>.
 *
 * @param symbol Integer representation of the character.
 * @return 1 if character is alphabetic or numeric, 0 otherwise.
 */
int	ft_isalnum(int symbol)
{
	if (ft_isdigit(symbol) || ft_isalpha(symbol))
		return (1);
	return (0);
}

/*int main(void)
{
    for (int c = -128; c <= 255; c++)
    {
        if (ft_isalnum(c) != (isalnum(c) != 0))
            printf("Mismatch for %d ('%c'): ft=%d, orig=%d\n",
                c, (char)c, ft_isalnum(c), isalnum(c) != 0);
    }
    printf("ft_isalnum test completed\n");
    return 0;
}*/