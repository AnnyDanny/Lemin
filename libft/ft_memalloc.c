/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:02:07 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/04 20:02:07 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = malloc(size);
	if (!s)
		return (NULL);
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
