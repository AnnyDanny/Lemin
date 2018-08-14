/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:50:18 by gdanylov          #+#    #+#             */
/*   Updated: 2018/05/29 15:50:19 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		check_width_prec(int i, char *format, t_struct *s)
{
	s->width = -1;
	s->p = -1;
	while (format[i] && (format[i] == '#' || format[i] == '0'
		|| format[i] == '-' || format[i] == '+' || format[i] == '.'
		|| (format[i] >= '0' && format[i] <= '9')))
	{
		if (format[i] > '0' && format[i] <= '9' && s->width == -1)
		{
			s->width = ft_atoi(&format[i]);
			i += (ft_strlen_int(s->width));
		}
		if (format[i] && format[i] == '.')
		{
			s->p = ft_atoi(&format[i + 1]);
			if (format[i + 1] >= '0' && format[i + 1] <= '9')
				i += (ft_strlen_int(s->p));
		}
		i++;
	}
}

int			check(t_struct *s, t_arg f, int *count, va_list arg)
{
	if (f.f[++f.i] == 0)
		return (f.i);
	check_flags(&f.i, f.f, s);
	check_width_prec(f.i, f.f, s);
	while (f.f[f.i] && (f.f[f.i] == '#' || f.f[f.i] == '0'
		|| f.f[f.i] == '-' || f.f[f.i] == '+' || f.f[f.i] == '.'
		|| f.f[f.i] == 'h' || f.f[f.i] == 'j' || f.f[f.i] == 'l'
		|| f.f[f.i] == 'z' || (f.f[f.i] >= '0' && f.f[f.i] <= '9')))
	{
		(f.i)++;
	}
	if (f.f[f.i] == 'p' || f.f[f.i] == 's' || f.f[f.i] == 'c'
		|| f.f[f.i] == 'd' || f.f[f.i] == 'i' || f.f[f.i] == 'C'
		|| f.f[f.i] == 'D' || f.f[f.i] == 'u' || f.f[f.i] == 'U'
		|| f.f[f.i] == 'x' || f.f[f.i] == 'X' || f.f[f.i] == 'o'
		|| f.f[f.i] == 'O' || f.f[f.i] == 'S' || f.f[f.i] == '%')
		s->sp = f.f[(f.i)++];
	*count += check_types(s, arg, 0);
	return (f.i);
}

int			ch_f(char *format, t_struct *s, va_list arg, int count)
{
	t_arg		f;

	f.i = 0;
	f.f = format;
	clear_struct(s);
	while (format[f.i])
	{
		if (format[f.i] == '%')
			f.i = check(s, f, &count, arg);
		if (format[f.i] && format[f.i] != '%')
		{
			if (s->flags[MINUS] == 0 && s->sp == 0)
				count = print_spaces(s, count);
			if (s->sp == 0)
				count = print_nulls(s, count);
			write(1, &format[f.i], 1);
			count++;
			f.i++;
			if (s->flags[MINUS] && s->sp == 0)
				count = print_spaces(s, count);
		}
		clear_struct(s);
	}
	return (count);
}

int			ft_printf(char *format, ...)
{
	t_struct		s;
	va_list			arg;
	int				count;

	count = 0;
	clear_struct(&s);
	va_start(arg, format);
	count = ch_f(format, &s, arg, count);
	va_end(arg);
	return (count);
}
