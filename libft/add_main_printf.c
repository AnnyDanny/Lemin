/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_main_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:55:04 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 21:55:05 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		clear_struct(t_struct *s)
{
	s->sp = 0;
	s->flags[PLUS] = 0;
	s->flags[MINUS] = 0;
	s->flags[HASH] = 0;
	s->flags[SPACE] = 0;
	s->flags[ZERO] = 0;
	s->flags[H] = 0;
	s->flags[L] = 0;
	s->flags[HH] = 0;
	s->flags[LL] = 0;
	s->flags[Z] = 0;
	s->flags[J] = 0;
	s->width = 0;
	s->p = -1;
	s->l2 = 0;
	s->i = 0;
	s->l2 = 0;
}

int			check_space(t_struct *s)
{
	if (s->sp == 0 && s->flags[SPACE] != 0)
	{
		s->flags[SPACE] = 0;
		return (1);
	}
	return (0);
}

int			print_spaces(t_struct *s, int count)
{
	int spaces;

	spaces = 0;
	if (s->width && s->p == -1)
		spaces = s->width - 1;
	while (spaces > 0)
	{
		write(1, " ", 1);
		spaces--;
		count++;
	}
	return (count);
}

int			print_nulls(t_struct *s, int count)
{
	int		nulls;

	nulls = 0;
	if (s->width && s->p == 0)
		nulls = s->width - 1;
	while (nulls > 0)
	{
		write(1, "0", 1);
		nulls--;
		count++;
	}
	return (count);
}
