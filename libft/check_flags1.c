/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:00:55 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/13 00:00:55 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			check_flags1(int *i, char *format, t_struct *s)
{
	if (s->flags[0] != '+')
		if (format[*i] == '+')
			s->flags[0] = format[*i];
}

void			check_flags2(int *i, char *format, t_struct *s)
{
	if (s->flags[1] != '-')
		if (format[*i] == '-')
			s->flags[1] = format[*i];
}

void			check_flags3(int *i, char *format, t_struct *s)
{
	if (s->flags[2] != '#')
		if (format[*i] == '#')
			s->flags[2] = format[*i];
}

void			check_flags4(int *i, char *format, t_struct *s)
{
	if (s->flags[3] != ' ')
		if (format[*i] == ' ')
			s->flags[3] = format[*i];
}

void			check_flags5(int *i, char *format, t_struct *s)
{
	if (s->flags[4] != '0')
		if (format[*i] == '0')
			s->flags[4] = format[*i];
}
