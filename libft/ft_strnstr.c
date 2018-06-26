/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:53:02 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/23 17:53:03 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	if (!*little)
		return ((char *)big);
	len = ft_strlen(little);
	while (big[i] && len <= n)
	{
		if (ft_strncmp(&big[i], little, len) == 0)
			return ((char *)&big[i]);
		i++;
		n--;
	}
	return (NULL);
}
