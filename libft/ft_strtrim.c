/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:25:31 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/13 21:25:31 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		start;
	char	*str;

	i = 0;
	k = 0;
	start = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == ',' || s[i] == '\n')
		i++;
	start = i;
	if (s[i] == '\0')
		return (ft_strdup(""));
	while (s[i] != '\0')
		i++;
	while (s[i] == '\0' || s[i] == '\t' ||
	s[i] == '\n' || s[i] == ' ' || s[i] == ',')
		i--;
	str = ft_strsub(s, start, (i - start + 1));
	return (str);
}
