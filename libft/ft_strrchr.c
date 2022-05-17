/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:24:21 by kwarpath          #+#    #+#             */
/*   Updated: 2021/10/11 20:10:51 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	last;

	last = c;
	i = ft_strlen((char *) s);
	if (last == '\0')
		return ((char *)s + i);
	while (i--)
	{
		if (last == s[i])
			return ((char *)s + i);
	}
	return (NULL);
}
