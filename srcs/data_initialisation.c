/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:52:06 by jnidorin          #+#    #+#             */
/*   Updated: 2022/02/23 15:54:07 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_new_list(int num, int index)
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

void	lstadd_back(t_node **stack_a, t_node *new)
{
	t_node	*lst_start;

	if (new == NULL)
		return ;
	lst_start = *stack_a;
	if (lst_start)
	{
		if (lst_start->prev)
		{
			lst_start->prev->next = new;
			new->prev = lst_start->prev;
			new->next = lst_start;
			lst_start->prev = new;
		}
		else
		{
			lst_start->prev = new;
			lst_start->next = new;
			new->prev = lst_start;
			new->next = lst_start;
		}
	}
	else
		*stack_a = new;
	return ;
}

int	ft_arr_len(char **arr)
{
	int	len;

	len = 0;
	if (arr == NULL)
		return (0);
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
