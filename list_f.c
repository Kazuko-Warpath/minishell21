/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgijvasilcikov <georgijvasilcikov@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:33:56 by georgijvasi       #+#    #+#             */
/*   Updated: 2022/06/16 14:04:04 by georgijvasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ififis(t_list	*tmp)
{
	if (ft_strncmp("|", tmp->content, 1))
	{
		ft_cmdadd_back(&g_line.cmd, ft_cmdnew());
		count_cmd(tmp);
	}
}
