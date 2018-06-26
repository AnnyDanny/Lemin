/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:08:33 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/01 18:20:36 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*fdest;
	const unsigned char	*fsrc;

	fdest = (unsigned char *)dest;
	fsrc = (unsigned char *)src;
	if (fsrc < fdest)
	{
		fsrc = fsrc + n;
		fdest = fdest + n;
		while (n)
		{
			*--fdest = *--fsrc;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*fdest++ = *fsrc++;
			n--;
		}
	}
	return (dest);
}
