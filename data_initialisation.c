#include "push_swap.h"

t_node	*new_list(int num, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (list == NULL)
		return (NULL);
	list->num = num;
	list->flag = 0;
	list->index = index;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

int ft_arr_len(char **arr)
{
    int len;

    len = 0;
    while (arr[len])
        len++;
    return (len);
}

t_all	*ft_init_struct(char **arr)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (all == NULL)
		return (NULL);
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = ft_arr_len(arr);
	all->size_b = 0;
	all->min_a = 1;
	return (all);
}