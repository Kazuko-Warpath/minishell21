/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:25:28 by kwarpath          #+#    #+#             */
/*   Updated: 2021/10/18 20:51:56 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	if (!needle[0])
		return ((char *) haystack);
	while (*haystack && len >= i)
	{
		if (!ft_strncmp(haystack, needle, i))
			return ((char *) haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
