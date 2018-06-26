/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:46:53 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/01 22:14:19 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	while (src[i] && i != n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i != n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
