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
typedef struct  s_state
{
	t_stack a;
	t_stack b;
	int     print;
	long	ops_count;
} t_state;
t_node  *stack_node_new(int value);
t_stack stack_new(char name);
t_node  *stack_pop_top(t_stack *stack);
void    stack_push_top(t_stack *stack, t_node *node);
void    stack_rotate(t_stack *stack);
void    stack_reverse_rotate(t_stack *stack);
void    stack_swap_top(t_stack *stack);
void	stack_push_bottom(t_stack *stack, t_node *node);
void    op_sa(t_state *state);
void    op_sb(t_state *state);
void    op_ss(t_state *state);
void	op_pa(t_state *state);
void	op_pb(t_state *state);
void	op_ra(t_state *state);
void	op_rb(t_state *state);
void	op_rr(t_state *state);
void	op_rra(t_state *state);
void	op_rrb(t_state *state);
void	op_rrr(t_state *state);
void 	op_print(t_state *state, const char *op);
void	error_exit(t_state *state);
void	free_state(t_state *state);
void	parse_args(t_state *state, int argc, char **argv);
int		is_valid_number(const char *num, int *all_zero_flag);
long	ft_atol(const char *num, int *num_int_flag);
int		assign_indexes(t_stack *a);
int		ft_merge_sort_ints(int *arr, int left, int right);
int		find_index(const int *arr, int size, int value);
int		is_sorted_stack(const t_stack *a);

#endif