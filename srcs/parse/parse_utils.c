#include "push_swap.h"

long ft_atol(const char *num, int *num_int_flag)
{
	int		i;
	int		sign;
	long	res;
	
	if (!num || !num_int_flag)
		return (0);
	*num_int_flag = 1;
	i = 0;
	res = 0;
	sign = 1;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10;
		res = res + (num[i] - '0') * sign;
		if (res > INT_MAX || res < INT_MIN)
			return (*num_int_flag = 0, 0);
		i++;
	}
	return (res);
}
