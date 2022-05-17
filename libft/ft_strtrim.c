/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:03:05 by kwarpath          #+#    #+#             */
/*   Updated: 2021/10/19 18:31:01 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chaekset(char c, char const *set)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (set[i])
	{
		if (set[i] == c)
			check = 0;
		i++;
	}
	return (check);
}

static int	ft_indexstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (chaekset(s1[i], set) == 1)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_indexend(char const *s1, char const *set, int start)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (s1[i] && i > start)
	{
		if (chaekset(s1[i], set) != 0)
			return (i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_indexstart(s1, set);
	if (start == -1)
		return (ft_strdup(""));
	end = ft_indexend(s1, set, start);
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
