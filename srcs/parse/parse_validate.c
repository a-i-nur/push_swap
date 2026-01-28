#include "push_swap.h"

static int	check_digit(char num, int *count)
{
	if (!ft_isdigit(num))
		return (0);
	if (num != '0')
		(*count)++;
	else if (*count > 0)
		(*count)++;
	return (1);
}

int	is_valid_number(const char *num, int *all_zero_flag)
{
	int	i;
	int	sign;
	int	count;

	if (!num || !num[0] || !all_zero_flag)
		return (0);
	sign = 0;
	count = 0;
	*all_zero_flag = 0;
	if (num[0] == '+' || num[0] == '-')
		sign++;
	i = sign;
	while (num[i])
	{
		if (!check_digit(num[i], &count))
			return (0);
		i++;
	}
	if (count > 10 || i == sign)
		return (0);
	if (num[i - 1] == '0' && count == 0)
		*all_zero_flag = 1;
	return (1);
}
