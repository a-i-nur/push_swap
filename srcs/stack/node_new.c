#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
    new_node->index = 0;
	new_node->next = NULL;
    new_node->prev = NULL;
	return (new_node);
}
