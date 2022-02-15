#include "push_swap.h"

t_all	*ft_parsing_args(char **argv)
{
	t_all	*all;
	char	**arr;

	arr = ft_readline(argv);
	ft_check_input_numbers(arr);
	ft_check_for_doubles(arr);
	all = ft_init_struct(arr);
	//add_to_stack(all, arr);
	//free_arr(arr, 0);
	//return (all);
}

int main(int argc, char **argv)
{
    t_all	*all;

	if (argc > 1)
	{
		all = ft_parsing_args(argv);
		//sorting(all);
		//free_stack(all);
	}
}