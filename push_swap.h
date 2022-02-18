#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
#include <stdio.h>

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
}                   t_node;

// Каждый стек - отдельный двусвязный список
// Длина стека нужна для перемещения по закольцованному списку
// min_a индекс первого элемента отсортированного массива, как только нашли минимальный элемент и поместили в низ стека А, увеличивается на 1. Изначально равна 1.
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

// parsing and validation.c
char	**ft_readline(char **av);
void	ft_check_input_numbers(char **arr);
void ft_check_for_doubles(char **arr);
void	ft_free_arr(char **arr, int flag);

// data_initialisation.c
t_all	*ft_init_struct(char **arr);
int ft_arr_len(char **arr);
t_node	*ft_new_list(int num, int index);
void	lstadd_back(t_node **stack_a, t_node *new);

// parser_add.c
void	ft_prepare_for_stack(t_all *all, char **arr);
void	free_stack(t_all *all);


#endif
