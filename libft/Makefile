
NAME	=	libft.a

SRCS	=	ft_isalpha.c	ft_memcpy.c	ft_tolower.c	ft_bzero.c\
		ft_isascii.c	ft_memmove.c	ft_strncmp.c	ft_toupper.c\
		ft_isdigit.c	ft_memset.c	ft_isalnum.c	ft_isprint.c\
		ft_strlen.c	ft_strlcpy.c	ft_strrchr.c	ft_strchr.c\
		ft_memchr.c	ft_putstr_fd.c	ft_putchar_fd.c	ft_putendl_fd.c\
		ft_strdup.c	ft_strmapi.c	ft_calloc.c	ft_memcmp.c\
		ft_atoi.c	ft_strlcat.c	ft_strnstr.c	ft_putnbr_fd.c\
		ft_substr.c	ft_striteri.c	ft_strjoin.c	ft_strtrim.c\
		ft_itoa.c	ft_split.c	
		


SRCS_B	=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstadd_back.c\
		ft_lstadd_back.c	ft_lstlast.c		ft_lstdelone.c	ft_lstiter.c\
		ft_lstmap.c		ft_lstclear.c
				

HEADER  =	libft.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

OBJ_B	=	$(SRCS_B:%.c=%.o)
 
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)
 
.PHONY	:	all clean fclean re bonus
 
all		:	$(NAME)
 
$(NAME)	:	$(OBJ) $(HEADER)
		@echo "\tCompilation of $(NAME)"
		@ar rcs $(NAME) $?
		@echo "\tCompilation done!"
 
%.o		:	%.c $(HEADER)
		@$(CC) $(FLAGS) -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

bonus	:
		@echo "\tBonus part compilation"
		@make OBJ="$(OBJ_B)" all
		@echo "\tCompilation done!"

clean	:
		@echo "\tDeleting .o files"
		@rm -f $(OBJ)
		@echo "\tDeleting done!"
 
fclean	:	clean
		@echo "\tDeleting $(NAME)"
		@rm -f $(OBJ) $(OBJB)
		@rm -f $(NAME)
		@echo "\tDeleting done!"
 
re		:	fclean all
 