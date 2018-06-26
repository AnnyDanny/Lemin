/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:29:16 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/13 21:29:16 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *arr, char c)
{
	int i;
	int countwords;

	i = 0;
	countwords = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			i++;
		if (arr[i] != c)
		{
			while (arr[i] != c && arr[i] != '\0')
				i++;
			countwords++;
		}
	}
	return (countwords);
}

static int		ft_countw(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char		**ft_copy(const char *s, char **m, char c)
{
	int		i;
	int		num;
	int		numbstr;

	i = 0;
	num = 0;
	numbstr = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			m[num] = (char *)malloc(sizeof(char) * (ft_countw(&s[i], c) + 1));
			while (s[i] != c && s[i] != '\0')
				m[num][numbstr++] = s[i++];
			m[num][numbstr] = '\0';
			num++;
			numbstr = 0;
		}
	}
	m[num] = NULL;
	return (m);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**m;

	if (!s)
		return (NULL);
	m = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!m)
		return (NULL);
	m = ft_copy(s, m, c);
	return (m);
}
