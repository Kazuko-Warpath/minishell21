/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgijvasilcikov <georgijvasilcikov@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:34:58 by georgijvasi       #+#    #+#             */
/*   Updated: 2022/06/11 19:35:26 by georgijvasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	warning(char *msg, int code, int errstd)
{
	if (errstd && code > 0 && code < 107)
	{
		perror(msg); //печатаем сообщение перед выводом ошибки
		exit(code); // выход (код ошибки - текст выведенный по завершению програмы)
	}
	if (!errstd)
		printf("%s\n", msg);
	else
		write(2, msg, ft_strlen(msg));
	exit(code);
}

void	ft_free_list(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (a)
	{
		tmp = a->next;
		free(a->content);
		free(a);
		a = tmp;
	}
}

void	ft_free(char **mass)
{
	int	sizemass;

	sizemass = 0;
	while (mass[sizemass])
	{
		free(mass[sizemass]);
		sizemass++;
	}
	free(mass);
}

void	errmsg(char *s1, char *s2, char *s3, int code)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	ft_putstr_fd("\n", 2);
	if (code < 0)
		g_line.status = -code;
	else
		exit(code);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
