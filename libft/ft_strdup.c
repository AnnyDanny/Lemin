/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:42:24 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/01 19:01:40 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (str && str[i])
		i++;
	if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
