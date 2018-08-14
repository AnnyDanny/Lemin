/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i_bd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:28:01 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 20:28:01 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long				check_flags_d(long long d, t_struct *s)
{
	if (s->flags[H] == 1 && s->sp != 'D')
		return ((short)d);
	else if (s->flags[LL] == 2 || s->sp == 'D')
		return ((long long)d);
	else if (s->flags[L] == 1)
		return ((long)d);
	else if (s->flags[HH] == 2 && s->sp != 'D')
		return ((char)d);
	else if (s->flags[Z] != 0 || s->flags[J] != 0)
		return ((size_t)d);
	return ((int)d);
}

int						check_plus_minus(long long d, int count, t_struct *s)
{
	if (d < 0)
	{
		write(1, "-", 1);
		count++;
	}
	if (s->flags[PLUS] && d >= 0)
	{
		write(1, "+", 1);
		count++;
	}
	return (count);
}

long long				check_all_d_i_bd(t_struct *s, va_list arg, int count)
{
	long long					d;
	int							len;
	char						*str;

	d = 0;
	len = 0;
	str = NULL;
	d = va_arg(arg, long long);
	d = check_flags_d(d, s);
	str = ft_itoa(d);
	if (!(d == 0 && s->p == 0))
		len = ft_strlen(str);
	if (s->flags[MINUS] == 0)
		count = print_spaces_d(s, len, count, d);
	count = check_plus_minus(d, count, s);
	count = print_nulls_d(s, len, count, d);
	if (!(d == 0 && s->flags[ZERO] && s->flags[SPACE]))
	{
		write(1, str, len);
		count += len;
	}
	if (s->flags[MINUS])
		count = print_spaces_d(s, len, count, d);
	ft_strdel(&str);
	return (count);
}
