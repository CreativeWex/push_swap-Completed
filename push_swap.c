#include "push_swap.h"

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

void	sorting(t_all *all)
{
	if (ft_is_sort_true(all))
		ft_free_stack(all);
	if (all->size_a < 6)
	{
		//sort_five(all);
		ft_free_stack(all);
	}
	/*
	move_a_to_b_first(all);
	while (!(sort_true(all) && all->size_b == 0))
	{
		if (all->size_b > 0 && all->size_b < 6)
			sort_b_to_a_five(all);
		else if (all->size_b >= 6)
			move_b_to_a(all);
		if (all->size_b == 0)
		{
			sort_a_to_b_five(all, 0, 0, 0);
			move_a_to_b(all);
		}
	}*/
}

int main(int argc, char **argv)
{
    t_all	*all;

	if (argc > 1)
	{
		all = ft_parsing_args(argv);

		all++;//!!!!!!!!!!
		
		//sorting(all);
		//ft_free_stack(all);
	}
	return (0);
}