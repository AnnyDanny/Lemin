/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_o_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:59:56 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 17:59:57 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		check_flags_u(unsigned long long u, t_struct *s)
{
	if ((s->sp == 'U' && s->flags[H] != 1 && s->flags[L] != 1
		&& s->flags[HH] != 2 && s->flags[LL] != 2 && s->flags[Z] == 0
		&& s->flags[J] == 0)
		|| (s->sp == 'U' && s->flags[H] == 1))
		return (u);
	else if (s->sp == 'u' && s->flags[H] == 1)
		return ((unsigned short)u);
	else if (s->sp == 'u' && s->flags[HH] == 2)
		return ((unsigned char)u);
	else if (s->sp == 'U' && s->flags[HH] == 2)
		return ((unsigned short)u);
	else if ((s->sp == 'u' && (s->flags[LL] == 2 || s->flags[L] == 1))
		|| s->sp == 'U')
		return (u);
	else if ((s->sp == 'u' || s->sp == 'U') && (s->flags[Z] != 0
		|| s->flags[J] != 0))
		return ((size_t)u);
	else if (s->sp == 'u')
		return ((unsigned)u);
	return (u);
}

int						print_spaces_o(t_struct *s, int len, int count)
{
	int							spaces;

	spaces = 0;
	if (s->flags[ZERO] == '0' && s->flags[MINUS] == 0)
		return (count);
	if (s->width)
		spaces = s->width - ((len > s->p) ? len : s->p);
	if (s->flags[HASH])
		spaces--;
	if (spaces <= 0 && s->flags[PLUS] == 0 && s->flags[MINUS] == 0
		&& s->flags[SPACE] != 0 && s->sp != 'u' && s->sp != 'o')
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

int						print_nulls_o(t_struct *s, int len, int count)
{
	int					nulls;

	nulls = 0;
	if (s->p == -1 && s->flags[ZERO] && s->flags[MINUS] == 0)
		nulls = s->width - len;
	if (s->p == -1 && s->flags[ZERO] && s->flags[PLUS] &&
		s->flags[MINUS] == 0)
		nulls = s->width - len - 1;
	if (s->p == -1 && (s->flags[ZERO] || s->flags[ZERO] == 0)
		&& s->flags[PLUS] && s->flags[MINUS])
		nulls = s->p - len;
	else if ((s->p != -1 && s->flags[MINUS] == 0)
		|| (s->p != 1 && s->flags[MINUS]))
		nulls = s->p - len;
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}

int						check_null_o(unsigned long long nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

unsigned long long		check_flags_o(unsigned long long o, t_struct *s)
{
	if (s->flags[HH] == 2 && s->sp != 'O')
		return ((unsigned char)o);
	else if (s->flags[H] == 1 && s->sp != 'O')
		return ((unsigned short)o);
	else if (s->flags[LL] == 2 || s->sp == 'O')
		return ((unsigned long long)o);
	else if (s->flags[L] == 1)
		return ((unsigned long)o);
	else if (s->flags[Z] != 0 || s->flags[J] != 0)
		return ((size_t)o);
	return ((unsigned int)o);
}
