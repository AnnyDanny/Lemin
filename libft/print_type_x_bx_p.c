/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_x_bx_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:06:26 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 18:06:27 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					print_hexa_x_p(unsigned long long nbr)
{
	int							k;
	char						*res;
	int							len;

	k = 0;
	res = NULL;
	len = ft_hex_len(nbr, 16);
	k = len;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	res = (char*)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	hexa(nbr, len, res);
	write(1, res, k);
	ft_strdel(&res);
	return (k);
}

int					print_hexa_p(t_struct *s, va_list arg, int count)
{
	int							len;
	unsigned long long			p;

	len = 0;
	p = va_arg(arg, unsigned long long);
	len = ft_hex_len(p, 16);
	if (p == 0 && s->p == -1 && s->flags[MINUS] == 0 && s->width == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	if (s->flags[MINUS] == 0)
		count = s_p(s, len, count, p);
	write(1, "0x", 2);
	count += 2;
	count = p_z(s, len, count, p);
	if (!(p == 0 && s->p == 0))
		count += print_hexa_x_p(p);
	if (s->flags[MINUS])
		count = s_p(s, len, count, p);
	return (count);
}

int					print_type_x(t_struct *s, va_list arg, int count)
{
	int							len;
	unsigned long long			x;

	len = 0;
	x = va_arg(arg, unsigned long long);
	x = check_flags_x(x, s);
	len = ft_hex_len(x, 16);
	if (s->flags[MINUS] == 0)
	{
		if (x == 0 && s->width && (s->p == -1 || s->p == 0))
			len -= 1;
		count = print_spaces_x(s, len, count);
	}
	count = check_hash_x(x, s, count);
	count = print_nulls_x(s, len, count, x);
	if (!(x == 0 && s->p == 0))
		count += print_hexa_x_p(x);
	if (s->flags[MINUS])
	{
		count = print_spaces_x(s, len, count);
	}
	return (count);
}

int					print_hexa_uni_x(unsigned long long int nbr)
{
	if (nbr >= 16)
		print_hexa_uni_x(nbr / 16);
	if ((nbr % 16) < 10)
		ft_putchar((nbr % 16) + 48);
	else
		ft_putchar((nbr % 16) - 10 + 65);
	return (nbr);
}

int					print_type_uni_x(t_struct *s, va_list arg, int count)
{
	unsigned long long			x;
	int							len;

	len = 0;
	x = va_arg(arg, unsigned long long);
	x = check_flags_x(x, s);
	len = ft_hex_len(x, 16);
	if (x == 0 && s->p == -1)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	count = check_hash(x, s, count);
	if (s->flags[MINUS] == 0)
		count = print_spaces_x(s, len, count);
	count = print_nulls_x(s, len, count, x);
	if (!(x == 0 && s->p == 0))
	{
		print_hexa_uni_x(x);
		count += len;
	}
	if (s->flags[MINUS])
		count = print_spaces_x(s, len, count);
	return (count);
}
