/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:07:32 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/07 13:05:22 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_symb(int num, int *sign)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		*sign = -1;
	}
	else if (num == 0)
		count++;
	while (num != 0)
	{
		num = (num - num % 10) / 10;
		count++;
	}
	return (count);
}

static void	ft_trans(int n, char *num, int len_num, int sign)
{
	int	digit;
	int	i;

	i = len_num - 1;
	while (i >= 0)
	{
		if (sign < 0 && i == 0)
		{
			num[i] = '-';
			break ;
		}
		digit = n % 10;
		num[i] = (digit * sign) + '0';
		n = (n - digit) / 10;
		i--;
	}
}

/**
 * @brief Convert an int to a newly allocated string.
 *
 * Produces the decimal textual representation of @p n (base 10) including
 * a leading '-' for negative values. Returns NULL on allocation failure.
 *
 * @param n Integer to convert.
 * @return char* Newly allocated string representation, or NULL.
 */
char	*ft_itoa(int n)
{
	char	*num;
	int		len_num;
	int		sign;

	sign = 1;
	len_num = ft_count_symb(n, &sign);
	num = (char *)malloc((len_num + 1) * sizeof(char));
	if (!num)
		return (NULL);
	ft_trans(n, num, len_num, sign);
	num[len_num] = '\0';
	return (num);
}
/*int main()
{
	int n_plus = 10000;
	int n_minus = -11;
	printf("plus = \"%s\", minus = \"%s\"\n", ft_itoa(n_plus), ft_itoa(n_minus));
	return (0);
}*/

/*static void             ft_print_result(char *s)
{
        int             len;

        if (!s)
                write(1, "NULL", 4);
        else
        {
                len = 0;
                while (s[len])
                        len++;
                write(1, s, len);
                free(s);
        }
}

int                             main(int argc, const char *argv[])
{
        int             arg;

        alarm(5);
        if (argc == 1)
                return (0);
        else if ((arg = atoi(argv[1])) == 1)
                ft_print_result(ft_itoa(0));
        else if (arg == 2)
                ft_print_result(ft_itoa(9));
        else if (arg == 3)
                ft_print_result(ft_itoa(-9));
        else if (arg == 4)
                ft_print_result(ft_itoa(10));
        else if (arg == 5)
                ft_print_result(ft_itoa(-10));
        else if (arg == 6)
                ft_print_result(ft_itoa(8124));
        else if (arg == 7)
                ft_print_result(ft_itoa(-9874));
        else if (arg == 8)
                ft_print_result(ft_itoa(543000));
        else if (arg == 9)
                ft_print_result(ft_itoa(-2147483648LL));
        else if (arg == 10)
                ft_print_result(ft_itoa(2147483647));
        return (0);
}*/
