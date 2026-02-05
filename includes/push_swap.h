/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:40:04 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/30 12:40:07 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define SMALL_SORT_MAX 5

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	char	name;
	int		size;
}	t_stack;
typedef struct s_state
{
	t_stack	a;
	t_stack	b;
	int		print;
	long	ops_count;
}	t_state;
typedef struct s_mergevars
{
	int	left;
	int	right;
	int	middle;
}	t_mergevars;
typedef struct s_lis
{
	int		*arr_index;
	int		*len;
	int		*prev;
	int		*flags;
	int		best_len;
	int		best_index;
	int		count_non;
	t_node	*node;
}	t_lis;
typedef struct s_move
{
	int	pos_b;
	int	rot_a;
	int	rot_b;
	int	cost;
}	t_move;
t_node	*stack_node_new(int value);
t_stack	stack_new(char name);
t_node	*stack_pop_top(t_stack *stack);
void	stack_push_top(t_stack *stack, t_node *node);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);
void	stack_swap_top(t_stack *stack);
void	stack_push_bottom(t_stack *stack, t_node *node);
t_state	state_new(void);
void	state_free(t_state *state);
void	op_sa(t_state *state);
void	op_sb(t_state *state);
void	op_ss(t_state *state);
void	op_pa(t_state *state);
void	op_pb(t_state *state);
void	op_ra(t_state *state);
void	op_rb(t_state *state);
void	op_rr(t_state *state);
void	op_rra(t_state *state);
void	op_rrb(t_state *state);
void	op_rrr(t_state *state);
void	op_print(t_state *state, const char *op);
void	error_exit(t_state *state);
void	parse_args(t_state *state, int argc, char **argv);
int		is_valid_number(const char *num, int *all_zero_flag);
long	ft_atol(const char *num, int *num_int_flag);
int		assign_indexes(t_stack *a);
int		ft_merge_sort_ints(int *arr, int left, int right);
int		find_index(const int *arr, int size, int value);
int		is_sorted_stack(const t_stack *a);
void	sort_dispatch(t_state *state);
void	sort_small(t_state *state);
void	sort_small_2(t_state *state);
void	sort_small_3(t_state *state);
int		find_min_pos(const t_stack *stack);
int		find_max_pos(const t_stack *stack);
void	bring_pos_to_top(t_state *state, int pos, char stack_name);
void	sort_small_4(t_state *state);
void	sort_small_5(t_state *state);
void	lis_free(t_lis *lis, int with_flags);
t_lis	lis_new(const t_stack *a, int size);
int		*compute_lis_flags(const t_stack *a, int size, int *pivot_out);
void	push_chunks_a_to_b(t_state *state);
int		total_cost(int rot_a, int rot_b);
int		rotations_to_top(int size, int pos);
int		find_target_index_in_a(const t_stack *a, int x);
int		find_pos_by_index(const t_stack *stack, int index);
void	push_back_b_to_a_greedy(t_state *state);
void	final_rotate_min_to_top(t_state *state);
void	sort_big(t_state *state);

#endif
