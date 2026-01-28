#include "push_swap.h"

void	op_print(t_state *state, const char *op)
{
	int	res_printf;

	if (!state || !op || state->print == 0)
		return ;
	res_printf = ft_printf("%s\n", op);
	if (res_printf < 0)
		error_exit(state);
	state->ops_count++;
}
