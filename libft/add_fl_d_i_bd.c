/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fl_d_i_bd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:54:06 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 20:54:07 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						print_space(t_struct *s, int d, int count)
{
	if (s->flags[SPACE] && s->flags[ZERO] && d == 0)
	{
		write(1, " ", 1);
		count += 1;
	}
	return (count);
}

int						print_nulls_d(t_struct *s, int len, int count, int d)
{
	int						nulls;

	nulls = 0;
	if (s->p == -1 && s->flags[ZERO] && s->flags[MINUS] == 0)
		nulls = s->width - len;
	if (s->p == -1 && s->flags[ZERO] && (s->flags[PLUS]
		|| d < 0) && s->flags[MINUS] == 0)
		nulls = s->width - len - 1;
	if (s->p == -1 && (s->flags[ZERO] || s->flags[ZERO] == 0)
		&& s->flags[PLUS] && s->flags[MINUS])
		nulls = s->p - len;
	else if ((s->p != -1 && s->flags[MINUS] == 0)
		|| (s->p != 1 && s->flags[MINUS]))
		nulls = s->p - len;
	count = print_space(s, d, count);
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}

int						print_spaces_d(t_struct *s, int len, int count, int d)
{
	int spaces;

	spaces = 0;
	if (s->p == -1 && s->flags[ZERO] && s->flags[MINUS] == 0)
		return (count);
	if (s->width && d < 0)
		spaces = s->width - ((len > s->p) ? len : s->p) - 1;
	if (s->width && d >= 0)
		spaces = s->width - ((len > s->p) ? len : s->p);
	if (s->flags[PLUS])
		spaces--;
	if (spaces <= 0 && s->flags[PLUS] == 0 && s->flags[MINUS] == 0
		&& s->flags[SPACE] != 0 && d > 0)
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
