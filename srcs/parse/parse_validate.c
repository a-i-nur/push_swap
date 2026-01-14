#include "push_swap.h"

int	is_valid_number(const char *num)
{
	int	i;
	int	sign;
	int count;

	if (!num || !num[0])
		return (0);
	sign = 0;
	count = 0;
	if (num[0] == '+' || num[0] == '-')
		sign++;
	i = sign;
	while(num[i])
	{ 	
		if (!ft_isdigit(num[i]))
			return (0);
		if (num[i] != '0')
			count++;
		else if (count > 0)
			count++;
		i++;
	}
	if (count > 10 || i == sign)
		return (0);
	return (1);
}
