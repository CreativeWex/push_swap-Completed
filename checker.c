#include "push_swap.h"

void ft_space_checker()

/*void	space_checker(char *line)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\v' || arr[i] == '\n' || arr[i] == '\f' || arr[i] == '\r')
			ft_display_error();
	}
	return ;
}*/

int	ft_is_sort_true(t_all *all)
{
	int		i;
	t_node	*head;

	head = all->stack_a;
	i = all->size_a - 1;
	while (i-- > 0)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

static void	get_cmd(t_all *all, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(all, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(all, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(all, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(all, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(all, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(all, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(all, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(all, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(all, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(all, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(all, 0);
	else
		ft_display_error();
}

static void	checker(t_all *all)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		space_checker(line);
		get_cmd(all, line);
	}
	if (ft_is_sort_true(all))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_all	*ft_parsing_args(char **argv)
{
	t_all	*all;
	char	**arr;

	arr = ft_readline(argv);
	ft_check_input_numbers(arr);
	ft_check_for_doubles(arr);
	all = ft_init_struct(arr);
	ft_prepare_for_stack(all, arr);
	ft_free_arr(arr, 0);
	return (all);
}

int main(int argc, char **argv)
{
    t_all	*all;

	if (argc > 1)
	{
		all = parsing(argv);
		checker(all, argv);
		free_stack(all);
	}
	return (0);