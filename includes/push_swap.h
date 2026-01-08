#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct  s_node
{
	int             value;
	int             index;
	struct s_node   *next;  
	struct s_node   *prev;
} t_node;
typedef struct  s_stack
{
	t_node  *top;
	t_node  *bottom;
	char    name;
	int     size;
} t_stack;
t_node  *stack_node_new(int value);
t_stack stack_new(char name);
void    stack_push_top(t_stack *stack, t_node *node);
t_node  *stack_pop_top(t_stack *stack);
void    stack_rotate(t_stack *stack);
void    stack_reverse_rotate(t_stack *stack);

#endif
