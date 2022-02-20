NAME	=	push_swap

NAME_B	=	checker

SRCS	=	push_swap.c					data_initialisation.c 	parsing_and_validation.c\
			stack_base_operations.c 	median_operations.c 	cmd_pa_pb.c\
			cmd_ra_rb_rr.c				cmd_rra_rrb_rrr.c		small_group_sorting.c\
			cmd_sa_sb_ss.c				big_group_sorting.c

#SRCS_B	=	src/cheker.c		src/parser_check.c \
			src/parser_init.c 	src/parser_add.c 	src/cmd_push.c \
			src/cmd_swap.c		src/cmd_rotate.c 	src/cmd_reverse.c \
			src/sort_big.c		src/sort_med.c		src/sort_min.c

OBJ		=	$(SRCS:%.c=%.o)

#OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			@echo "$(BLUE)Compilation of $(NAME)\n$(END)"
			@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n\t Complited $(NAME) \n$(END)"

%.o:		%.c
			@$(CC) $(FLAGS)  -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
			@echo "$(BLUE)\nCleaning done!\n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@echo "$(BLUE)\n\tCleaning succeed\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\nDeleting done!\n$(END)"

re:			fclean all
			@echo "$(BLUE)\tRemake done\n$(END)"


