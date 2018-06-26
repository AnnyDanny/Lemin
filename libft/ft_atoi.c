/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:18:06 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/04 16:18:07 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	long long int	res;
	long long int	buff;

	i = 0;
	n = 1;
	res = 0;
	buff = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	(str[i] == '-') ? n = -1 : n;
	(str[i] == '-' || str[i] == '+') ? i++ : i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res < buff && n == -1)
			return (0);
		if (res < buff && n == 1)
			return (-1);
		buff = res;
		i++;
	}
	return (res * n);
}
