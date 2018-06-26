/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:00:47 by gdanylov          #+#    #+#             */
/*   Updated: 2017/10/31 19:07:19 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*fdst;
	unsigned char		*fsrc;

	i = 0;
	fdst = (unsigned char *)dst;
	fsrc = (unsigned char *)src;
	while (i < n)
	{
		fdst[i] = fsrc[i];
		i++;
	}
	return (fdst);
}
