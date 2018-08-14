/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:20:14 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 18:20:14 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						print_spaces_s(t_struct *s, int count, int len)
{
	int							spaces;

	spaces = 0;
	if (s->flags[ZERO] != 0)
		return (count);
	if (s->p != -1 && s->p < len)
		len = s->p;
	if (s->width != 0 && s->p == -1 && len == 0)
		spaces = s->width;
	if (s->width != 0 && s->p == -1)
		spaces = s->width - len;
	if (s->width != 0 && s->p != -1)
		spaces = s->width - len;
	while (spaces > 0)
	{
		write(1, " ", 1);
		spaces--;
		count++;
	}
	return (count);
}

int						print_nulls_s(t_struct *s, int count, int len)
{
	int							nulls;

	nulls = 0;
	if (s->p && s->flags[ZERO] && s->flags[MINUS] == 0)
		nulls = s->width - len;
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}

int						print_nulls_null(t_struct *s, int count)
{
	int							nulls;

	nulls = 0;
	if (s->width != 0 || s->flags[ZERO] != 0)
		nulls = s->width;
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}

int						print_type_s(t_struct *s, va_list arg, int count)
{
	char						*tmp;

	s->l1 = 0;
	tmp = NULL;
	s->str1 = NULL;
	s->str1 = va_arg(arg, char*);
	if (s->str1 == NULL)
	{
		count = print_nulls_null(s, count);
		tmp = ft_strdup("(null)");
	}
	else
		tmp = ft_strdup(s->str1);
	s->l1 = ft_strlen(tmp);
	if (s->flags[MINUS] == 0)
		count = print_spaces_s(s, count, s->l1);
	count = print_nulls_s(s, count, s->l1);
	if (s->p != -1 && s->p < s->l1)
		s->l1 = s->p;
	write(1, tmp, s->l1);
	count += s->l1;
	if (s->flags[MINUS])
		count = print_spaces_s(s, count, s->l1);
	ft_strdel(&tmp);
	return (count);
}
