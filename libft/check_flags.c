/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 02:17:38 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/07 02:17:39 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			check_flags6(int *i, char *format, t_struct *s)
{
	if (s->flags[5] != 1 && s->flags[7] != 2)
	{
		if (format[*i] == 'h')
		{
			if (format[(*i) + 1] == 'h')
			{
				(*i)++;
				s->flags[HH] = 2;
			}
			else
				s->flags[H] = 1;
		}
	}
}

void			check_flags7(int *i, char *format, t_struct *s)
{
	if (s->flags[9] != 'z')
		if (format[*i] == 'z')
			s->flags[9] = format[*i];
	if (s->flags[10] != 'j')
		if (format[*i] == 'j')
			s->flags[10] = format[*i];
}

void			check_flags8(int *i, char *format, t_struct *s)
{
	if (s->flags[6] != 1 && s->flags[8] != 2)
	{
		if (format[*i] == 'l')
		{
			if (format[*i + 1] == 'l')
			{
				(*i)++;
				s->flags[LL] = 2;
			}
			else
				s->flags[L] = 1;
		}
	}
}

void			check_flags(int *i, char *format, t_struct *s)
{
	while (format[*i] == '+' || format[*i] == '-' || format[*i] == '#'
	|| format[*i] == ' ' || format[*i] == '0' || format[*i] == 'h'
	|| format[*i] == 'l' || format[*i] == 'j'
	|| format[*i] == 'z')
	{
		check_flags1(i, format, s);
		check_flags2(i, format, s);
		check_flags3(i, format, s);
		check_flags4(i, format, s);
		check_flags5(i, format, s);
		check_flags6(i, format, s);
		check_flags7(i, format, s);
		check_flags8(i, format, s);
		(*i)++;
	}
}
