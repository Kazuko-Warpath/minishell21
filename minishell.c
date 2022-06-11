/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgijvasilcikov <georgijvasilcikov@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:34:14 by georgijvasi       #+#    #+#             */
/*   Updated: 2022/06/11 19:35:26 by georgijvasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quots_pipe(void)
{
	if (!check_quotes()) //скипаем "'"(не закрытая кавычка) если в строке ничего не остается возвращаем 0
	{
		errmsg("minishell: ", g_line.line, ": unclosed quotes", -21);
		add_history(g_line.line); //записываем в историю
		free(g_line.line);
		return (1);
	}
	if (!check_first_pipe()) // проверяем если запись команды начинается "|"
	{
		errmsg("minishell: syntax error near unexpected token `|'",
			NULL, NULL, -258);
		free(g_line.line);
		return (1);
	}
	return (0);
}

void	prompt_pipe(void)
{
	char	*tmpline;
	char	*tmpread;

	while (check_last_pipe(g_line.line))
	{
		tmpline = ft_strdup(g_line.line);
		free(g_line.line);
		tmpread = readline(" > ");
		g_line.line = ft_strjoin(tmpline, tmpread);
		free(tmpread);
		free(tmpline);
	}
}

void	handler_inside(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
	if (sig == SIGQUIT)
		write(1, "Quit: 3\n", 8);
}

void	prepare(void)
{	
	t_list	*tmp;

	add_history(g_line.line);
	dollar();
	parser();
	tmp = g_line.list;
	while (tmp)
	{
		tmp->content = (void *)rm_quotes(tmp->content);
		tmp = tmp->next;
	}
	get_cmd();
}

void	minishell(void)
{
	while (1)
	{
		init_g_line(); //инициализация
		g_line.line = readline("minishell > "); //записываем в line текст
		if (!g_line.line)
		{
			printf("\033[Aminishell > exit\n");
			exit(0);
		}
		else if (*g_line.line && ft_strlen(g_line.line))
		{
			if (check_quots_pipe())
				continue ; //идем в начало цикла
			prompt_pipe();
			prepare();
			signal(SIGINT, handler_inside);
			signal(SIGQUIT, handler_inside);
			pipex(g_line.cmd);
			free(g_line.line);
			ft_free_cmd(g_line.cmd);
			ft_free_list(g_line.list);
		}
	}
}
