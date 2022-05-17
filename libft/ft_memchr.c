/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:16:47 by kwarpath          #+#    #+#             */
/*   Updated: 2021/10/11 19:16:28 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*dst;

	dst = (unsigned char *) s;
	i = 0;
	while (0 < n)
	{
		if ((unsigned char) dst[i] == (unsigned char) c)
			return ((void *)&s[i]);
		i++;
		n--;
	}
	return (NULL);
}
