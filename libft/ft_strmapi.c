/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:32:52 by kwarpath          #+#    #+#             */
/*   Updated: 2021/10/18 20:39:37 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			dlina;
	char			*stroka;

	i = 0;
	if (!f || !s)
		return (NULL);
	dlina = ft_strlen(s);
	stroka = malloc((dlina + 1) * sizeof(char));
	if (!stroka)
		return (NULL);
	while (s[i])
	{
		stroka[i] = f(i, s[i]);
		i++;
	}
	stroka[i] = '\0';
	return (stroka);
}	
