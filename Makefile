NAME = minishell

HEADER = minishell.h

dirlibft = libft/

srcs = 	binary.c cmd_f.c dict_f.c dollar.c \
		ft_cd.c ft_cd2.c ft_echo_pwd_env_exit.c \
		ft_export.c ft_export2.c ft_unset.c \
		get_cmd.c list_f.c main.c minishell.c \
		parser.c pipes.c pipes2.c quotes.c \
		redirect.c utils.c utils2.c utils3.c

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
			@$(CC) $(FLAGS) -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include $(obj) $(LIB) -o $(NAME)

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@ -I/usr/local/opt/readline/include

clean:
			@$(RM) $(obj)
			@$(MAKE) -C $(dirlibft) clean

fclean:		clean
			@$(MAKE) -C $(dirlibft) fclean
			@$(RM) $(NAME)

re:			fclean all
