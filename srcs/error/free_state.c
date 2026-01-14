#include "push_swap.h"

void	ft_stack_clear(t_node **node)
{
	t_node	*tmp;

	if (!node)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		(*node) = tmp;
	}
	*node = NULL;
}

void	free_state(t_state *state)
{
    ft_stack_clear(&state->a.top);
    ft_stack_clear(&state->b.top);
    state->a.top = NULL;
    state->a.bottom = NULL;
    state->a.size = 0;
    state->b.top = NULL;
    state->b.bottom = NULL;
    state->b.size = 0;
    state->ops_count = 0;
}
