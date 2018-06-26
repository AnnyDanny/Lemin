/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:59:19 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/01 16:43:10 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*fdest;
	unsigned char		*fsrc;

	i = 0;
	fdest = (unsigned char *)dest;
	fsrc = (unsigned char *)src;
	while (i < n)
	{
		fdest[i] = fsrc[i];
		if (fdest[i] == (unsigned char)c)
			return (&fdest[i + 1]);
		i++;
	}
	return (NULL);
}
