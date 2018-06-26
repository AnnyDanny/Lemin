/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:08:33 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/01 18:20:36 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t num)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)dest;
	while (num-- != 0)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
