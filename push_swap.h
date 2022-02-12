#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> // для printf (после удалить)
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648


// int num - значение, которое нужно отсортировать
// int index - порядок в котором находится это значение в уже отсортированном массиве
// int flag - флаг (элемент стека А уже был в стеке Б)
// next - ссылка на следующий элемент, который нужно отсортировать
typedef struct s_node
{
	int				num;
	int				index;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}

// Каждый стек - отдельный двусвязный список
// Длина стека нужна для перемещения по закольцованному списку
typedef struct s_all
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	int				min;
	int				med;
	int				max;
	int				min_a;
}					t_all;

#endif
