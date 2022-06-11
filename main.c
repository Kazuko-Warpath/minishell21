/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgijvasilcikov <georgijvasilcikov@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:34:06 by georgijvasi       #+#    #+#             */
/*   Updated: 2022/06/11 19:35:26 by georgijvasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;

	i = 0;
	if (argc != 1)
	{
		errno = 7; // код ошибки
		warning(argv[0], errno, 1);
	}
	g_line.envp = new_envp(envp); //записываем окружение в структуру
	g_line.status = 0; // ?????
	minishell(); //запуск программы
	ft_free(g_line.envp); // освобождение копии окружения
	return (0);
}
