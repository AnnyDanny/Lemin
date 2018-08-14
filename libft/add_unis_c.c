/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_unis_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:22:18 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 18:22:18 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						print_spaces_c(t_struct *s, int count)
{
	int							spaces;

	spaces = 0;
	if (s->width != 0 && s->flags[ZERO] == 0)
	{
		spaces = s->width - 1;
	}
	if (s->width && s->flags[ZERO] && s->sp == '%' && s->flags[MINUS])
		spaces = s->width - 1;
	while (spaces > 0)
	{
		write(1, " ", 1);
		spaces--;
		count++;
	}
	return (count);
}

int						check_flags_c(t_struct *s)
{
	if (s->flags[L])
		return (1);
	return (0);
}

int						print_nulls_c(t_struct *s, int count)
{
	int							nulls;

	nulls = 0;
	if (s->flags[ZERO] && s->flags[MINUS] == 0 && s->width)
		nulls = s->width - 1;
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}

int						print_type_c(t_struct *s, va_list arg, int count)
{
	unsigned int			c;

	if (s->sp == 37)
		c = '%';
	else
		c = va_arg(arg, unsigned int);
	if (check_flags_c(s) == 1)
		count = print_type_uni_c(c, count);
	else
	{
		if (s->flags[MINUS] == 0)
			count = print_spaces_c(s, count);
		count = print_nulls_c(s, count);
		write(1, &c, 1);
		if (s->flags[MINUS] != 0)
			count = print_spaces_c(s, count);
		count += 1;
	}
	return (count);
}

int						pr_sp_u_s(t_struct *s, int len, int count, char c)
{
	int						spaces;

	spaces = 0;
	if (s->width > 0)
		spaces = s->width - len;
	while (spaces > 0)
	{
		write(1, &c, 1);
		spaces--;
		count++;
	}
	return (count);
}
