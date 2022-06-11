/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgijvasilcikov <georgijvasilcikov@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:35:10 by georgijvasi       #+#    #+#             */
/*   Updated: 2022/06/11 19:35:26 by georgijvasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_g_line(void)
{
	signal(SIGQUIT, SIG_IGN); // ctrl+/ игнорируется
	signal(SIGINT, handler); //ctrl+c
	if ((pipe(g_line.fd[0])) == -1) //дескриптор ввода
		warning("minishell: pipe: ", errno, 1);
	if ((pipe(g_line.fd[1])) == -1) //дескриптор вывода
		warning("minishell: pipe: ", errno, 1);
	if ((pipe(g_line.fd[2])) == -1) //дескриптор ошибок
		warning("minishell: pipe: ", errno, 1);
	g_line.list = NULL; //инициализация 
	g_line.cmd = NULL; //инициализация 
	g_line.line = NULL;//инициализация 
}

int	check_last_pipe(char *str)
{
	int	i;
	int	pipe;

	i = 0;
	pipe = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|')
			pipe = 1;
		else if (str[i] != ' ')
			pipe = 0;
		i++;
	}
	return (pipe);
}

void	handler(int signum)
{
	(void)signum;
	rl_on_new_line(); 
	rl_redisplay();
	printf("  \n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	check_quotes(void) // 
{
	int	i;

	i = 0;
	while (g_line.line[i] != '\0')
	{
		if (g_line.line[i] == '\'')
		{
			i++;
			while (g_line.line[i] != '\0' && g_line.line[i] != '\'')
				i++;
			if (g_line.line[i] == '\0')
				return (0);
		}
		if (g_line.line[i] == '"')
		{
			i++;
			while (g_line.line[i] != '\0' && g_line.line[i] != '"')
				i++;
			if (g_line.line[i] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_first_pipe(void)
{
	int	i;

	i = 0;
	while (g_line.line[i] != '\0' && g_line.line[i] == ' ')
		i++;
	if (g_line.line[i] == '|')
		return (0);
	else
		return (1);
}
