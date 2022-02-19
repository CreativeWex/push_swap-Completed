#include "push_swap.h"

//head становится next, все элементы сдвигаются на 1. Первый элемент становится последним.
void	ra(t_all *all, int flag)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->next;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_all *all, int flag)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->next;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_all *all, int flag)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		ra(all, 0);
		rb(all, 0);
		if (flag)
			write(1, "rr\n", 3);
	}
}