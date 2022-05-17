NAME = minishell

HEADER = 

dirlibft = libft/

srcs = 

obj = $(srcs:%.c=%.o)

LIB = libft/libft.a

СС		=	cc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

.PHONY:		all	clean	fclean	re	libft

all:		libft $(NAME)

libft:
			@$(MAKE) -C $(dirlibft)

$(NAME):	$(obj)
			$(CC) $(FLAGS) $(obj) $(LIB) -o $(NAME)

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(obj)
			@$(MAKE) -C $(dirlibft) clean

fclean:		clean
			@$(MAKE) -C $(dirlibft) fclean
			@$(RM) $(NAME)

re:			fclean all
