/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:14:31 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/02 22:14:32 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == ch)
			return (&s[i]);
		i--;
	}
	return (NULL);
}
