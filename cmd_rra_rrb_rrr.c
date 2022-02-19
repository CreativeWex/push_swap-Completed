#include "push_swap.h"

//head становится prev, все элементы сдвигаются на 1. Последний элемент становится первым.
void	rra(t_all *all, int flag)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->prev;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_all *all, int flag)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->prev;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_all *all, int flag)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		rra(all, 0);
		rrb(all, 0);
		if (flag)
			write(1, "rrr\n", 4);
	}
}