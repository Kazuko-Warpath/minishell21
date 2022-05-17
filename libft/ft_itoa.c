/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:32:36 by kwarpath          #+#    #+#             */
/*   Updated: 2021/10/20 17:59:14 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zapic(char *stroka, size_t dlina, long minicooper)
{
	while (minicooper != 0 && dlina > 0)
	{
		dlina--;
		stroka[dlina] = minicooper % 10 + '0';
		minicooper = minicooper / 10;
	}
	return (stroka);
}

static char	*ft_minicoopernt(char *stroka, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		stroka[i] = src[i];
		i++;
	}
	stroka[i] = '\0';
	return (stroka);
}

static size_t	ft_dlina_int_stroki(int n)
{
	size_t	dlina;

	dlina = 0;
	if (n == 0)
		dlina = 1;
	if (n == -2147483648)
	{
		n = n / (-10);
		dlina = 2;
	}
	else if (n < 0)
	{
		n = -n;
		dlina++;
	}
	while (n != 0)
	{
		n = n / 10;
		dlina++;
	}
	return (dlina);
}

char	*ft_itoa(int n)
{
	char	*stroka;
	size_t	dlina;
	long	minicooper;

	dlina = ft_dlina_int_stroki(n);
	stroka = malloc(dlina + 1);
	if (!stroka)
		return (NULL);
	minicooper = (long)n;
	if (minicooper == -2147483648)
		return (ft_minicoopernt(stroka, "-2147483648"));
	stroka[dlina] = '\0';
	if (minicooper < 0)
	{
		minicooper = (-1) * minicooper;
		stroka[0] = '-';
	}
	if (minicooper == 0)
		stroka[0] = '0';
	if (minicooper > 0 && dlina > 0)
		zapic(stroka, dlina, minicooper);
	return (stroka);
}
