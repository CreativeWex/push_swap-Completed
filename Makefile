NAME	=	push_swap

#NAME_B	=	checker

SRCS	=	push_swap.c		parsing_and_validation.c	data_initialisation.c \
			parser_add.c	#src/ps_print.c 		src/parser_check.c \
			src/cmd_swap.c	src/cmd_rotate.c	src/cmd_reverse.c \
			src/sort_big.c	src/sort_med.c		src/sort_optima.c \
			src/sort_min.c

#SRCS_B	=	src/cheker.c		src/parser_check.c \
			src/parser_init.c 	src/parser_add.c 	src/cmd_push.c \
			src/cmd_swap.c		src/cmd_rotate.c 	src/cmd_reverse.c \
			src/sort_big.c		src/sort_med.c		src/sort_min.c

OBJ		=	$(SRCS:%.c=%.o)

#OBJ_B	=	$(SRCS_B:%.c=%.o)

LIBFT		=	libft/libft.a

HEADER	=	push_swap.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

BLUE	=	\033[1;34m
END		=	\033[0m

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			@echo "$(BLUE)Compilation of $(NAME)\n$(END)"
			@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(BLUE)\nCompilation done!$(END)\n"

%.o:		%.c $(INCLUDE)$(HEADER)
			@${CC} ${CFLAGS} -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

#bonus:		libft $(OBJ_B)
#			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
#			@echo "$(TURQUOISE)\n\tComplited $(NAME_B) \n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@echo "$(BLUE)\nCleaning done!\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\nDeleting done!\n$(END)"

re:			fclean all
			@echo "$(BLUE)\nRemake done\n$(END)"

.PHONY:		all	clean	fclean	re	#bonus