#include "push_swap.h"

void	create_stack(t_all *all, int *sort, int *not_sort, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (not_sort[i] == sort[j])
			{
				lstadd_back(&all->stack_a, new_list(not_sort[i], j + 1));
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	free(not_sort);
	free(sort);
}

void	babble_sort(t_all *all, int *sort, int *not_sort, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = -1;
	count = 0;
	while (++i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
			if (sort[j] > sort[j + 1])
			{
				tmp = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = tmp;
				count++;
			}
			j++;
	}
	create_stack(all, sort, not_sort, len);
}

// not_sort - массив исходных данных
// sort - отсортированный массив
void	add_to_stack(t_all *all, char **arr)
{
	int	*not_sort;
	int	*sort;
	int	i;
	int	num;
	int	len;

	len = ft_arr_len(arr);
	not_sort = malloc(sizeof(int) * (len));
	sort = malloc(sizeof(int) * (len));
	i = -1;
	while (++i < len)
	{
		num = ft_atoi(arr[i]);
		not_sort[i] = num;
		sort[i] = num;
	}
	babble_sort(all, sort, not_sort, len);
}