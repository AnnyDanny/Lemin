/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:51:21 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/09 17:51:22 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count(long long i)
{
	int k;

	k = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i = -i;
	while (i >= 1)
	{
		i = i / 10;
		k++;
	}
	return (k);
}

char		*ft_itoa(long long n)
{
	int				i;
	long long		l;
	int				len;
	char			*str;

	str = NULL;
	if (n < -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	i = 0;
	l = n;
	len = count(l);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		l = -l;
	if (l == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (l && len >= 0)
	{
		str[len] = l % 10 + '0';
		l /= 10;
		len--;
	}
	return (str);
}
