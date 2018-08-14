/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_x_bx_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:10:01 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 18:10:02 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					print_spaces_x(t_struct *s, int len, int count)
{
	int							spaces;

	spaces = 0;
	if (s->flags[ZERO] == '0' && s->flags[MINUS] == 0)
		return (count);
	if (s->width)
		spaces = s->width - ((len > s->p) ? len : s->p);
	if (s->width && s->flags[HASH])
		spaces = s->width - ((len > s->p) ? len : s->p) - 2;
	if (s->flags[PLUS])
		spaces--;
	if (spaces <= 0 && s->flags[PLUS] == 0 && s->flags[MINUS] == 0
		&& s->flags[SPACE] != 0 && s->sp != 'u'
		&& s->sp != 'x' && s->sp != 'X')
	{
		write(1, " ", 1);
		count++;
	}
	while (spaces > 0)
	{
		write(1, " ", 1);
		spaces--;
		count++;
	}
	return (count);
}

int					print_nulls_x(t_struct *s, int len, int count, int x)
{
	int							nulls;

	nulls = 0;
	if (s->p == -1 && s->flags[ZERO] && s->flags[MINUS] == 0
		&& s->flags[HASH] != 0)
		nulls = s->width - len - 2;
	if (s->p == -1 && s->flags[ZERO] && s->flags[MINUS] == 0
		&& s->flags[HASH] == 0)
		nulls = s->width - len;
	if (s->p == -1 && s->flags[ZERO] && (s->flags[PLUS] || x < 0)
		&& s->flags[MINUS] == 0 && s->sp != 'u')
		nulls = s->width - len - 1;
	else if (s->p != -1 && s->flags[MINUS] == 0)
		nulls = s->p - len;
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}

unsigned long long	check_flags_x(unsigned long long x, t_struct *s)
{
	if ((s->sp == 'X' || s->sp == 'x') && s->flags[H] != 1
		&& s->flags[L] != 1
		&& s->flags[HH] != 2 && s->flags[LL] != 2 && s->flags[Z] == 0
		&& s->flags[J] == 0)
		return ((unsigned int)x);
	else if ((s->sp == 'X' || s->sp == 'x') && s->flags[H] == 1)
		return ((unsigned short)x);
	else if ((s->sp == 'X' || s->sp == 'x') && s->flags[L] == 1)
		return ((unsigned long)x);
	else if ((s->sp == 'X' || s->sp == 'x') && s->flags[HH] == 2)
		return ((unsigned char)x);
	else if ((s->sp == 'X' || s->sp == 'x') && s->flags[LL] == 2)
		return ((unsigned long long)x);
	else if ((s->sp == 'X' || s->sp == 'x') && (s->flags[Z] != 0
		|| s->flags[J] != 0))
		return ((size_t)x);
	return (x);
}

int					s_p(t_struct *s, int len, int count, unsigned long long p)
{
	int							spaces;

	spaces = 0;
	if (s->flags[ZERO])
		return (count);
	if (s->width && p == 0)
		spaces = s->width - 3;
	if (s->width && s->p <= len)
		spaces = s->width - len - 2;
	if (s->flags[PLUS])
		spaces--;
	while (spaces > 0)
	{
		write(1, " ", 1);
		spaces--;
		count++;
	}
	return (count);
}

int					p_z(t_struct *s, int len, int count, unsigned long long p)
{
	int							nulls;

	nulls = 0;
	if (s->p == -1 && s->width && p == 0 && s->flags[ZERO])
		nulls = s->width - 3;
	if (s->p && s->p >= len)
		nulls = s->p - len;
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}
