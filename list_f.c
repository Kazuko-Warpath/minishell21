/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgijvasilcikov <georgijvasilcikov@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:33:56 by georgijvasi       #+#    #+#             */
/*   Updated: 2022/06/11 19:35:26 by georgijvasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	if (!content)
		return (0);
	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->content = content;
	res->next = NULL;
	return (res);
}

void	ififis(t_list	*tmp)
{
	if (ft_strncmp("|", tmp->content, 1))
	{
		ft_cmdadd_back(&g_line.cmd, ft_cmdnew());
		count_cmd(tmp);
	}
}
