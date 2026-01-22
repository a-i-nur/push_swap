#include "push_swap.h"

static int	is_op_line(const char *line, const char *op, size_t len)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, op, len) != 0)
		return (0);
	if (line[len] == '\n' || line[len] == '\0')
		return (1);
	return (0);
}

int	apply_op_line(t_state *st, char *line)
{
	if (is_op_line(line, "sa", 2))
		op_sa(st);
	else if (is_op_line(line, "sb", 2))
		op_sb(st);
	else if (is_op_line(line, "ss", 2))
		op_ss(st);
	else if (is_op_line(line, "pa", 2))
		op_pa(st);
	else if (is_op_line(line, "pb", 2))
		op_pb(st);
	else if (is_op_line(line, "ra", 2))
		op_ra(st);
	else if (is_op_line(line, "rb", 2))
		op_rb(st);
	else if (is_op_line(line, "rr", 2))
		op_rr(st);
	else if (is_op_line(line, "rra", 3))
		op_rra(st);
	else if (is_op_line(line, "rrb", 3))
		op_rrb(st);
	else if (is_op_line(line, "rrr", 3))
		op_rrr(st);
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_state state;
	char    *line;

	if (argc < 2)
		return (0);
	state = state_new();
	state.print = 0;
	parse_args(&state, argc, argv);
	if (assign_indexes(&state.a) == 0)
		error_exit(&state);
	while ((line = get_next_line(0)) != NULL)
	{
		if (!apply_op_line(&state, line))
		{
			free(line);
			error_exit(&state);
		}
		free(line);
	}
	if (is_sorted_stack(&state.a) && state.b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	state_free(&state);
	return (0);
}
