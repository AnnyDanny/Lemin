/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:57:10 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 17:57:11 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa_u(unsigned long long n)
{
	unsigned long long				l;
	int								len;
	char							*str;

	l = n;
	len = 1;
	str = NULL;
	while (l > 9)
	{
		l /= 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int						print_octal(unsigned long long nbr)
{
	int							len;
	char						*res;
	int							k;

	res = NULL;
	len = ft_hex_len(nbr, 8);
	k = len;
	if (check_null_o(nbr) == 1)
		return (1);
	res = (char*)malloc(sizeof(char) * (len + 1));
	res[len--] = '\0';
	while (nbr >= 1 && len > 0)
	{
		if (nbr % 8 < 8)
			res[len--] = (nbr % 8) + 48;
		else if (nbr / 8 < 8)
			res[len--] = (nbr / 8) + 48;
		nbr /= 8;
	}
	res[len] = nbr + '0';
	write(1, res, k);
	ft_strdel(&res);
	return (k);
}

int						print_type_o(t_struct *s, va_list arg, int count)
{
	int							len;
	unsigned long long			o;

	len = 0;
	o = va_arg(arg, unsigned long long);
	o = check_flags_o(o, s);
	len = ft_hex_len(o, 8);
	if (s->flags[MINUS] == 0)
	{
		if (o == 0 && s->width && (s->p == -1 || s->p == 0))
			count = print_spaces_o(s, len - 1, count);
		else
			count = print_spaces_o(s, len, count);
	}
	if (s->flags[HASH] != 0 && o != 0 && s->p <= 0)
	{
		write(1, "0", 1);
		count += 1;
	}
	count = print_nulls_o(s, len, count);
	if (!(o == 0 && s->p == 0 && s->flags[HASH] == 0))
		count += print_octal(o);
	if (s->flags[MINUS])
		count = print_spaces_o(s, len, count);
	return (count);
}

int						print_type_u(t_struct *s, va_list arg, int count)
{
	unsigned long long			u;
	int							len;
	char						*str;

	str = NULL;
	u = va_arg(arg, unsigned long long);
	u = check_flags_u(u, s);
	if (s->sp == 'u')
		str = ft_itoa_u(u);
	else if (s->sp == 'U' || (s->sp == 'u' && (s->flags[L] == 1
		|| s->flags[LL] == 2)))
		str = ft_itoa_u(u);
	len = ft_strlen(str);
	if (s->flags[MINUS] == 0)
		count = print_spaces_x(s, len, count);
	count = print_nulls_x(s, len, count, u);
	if (!((u == 0) && (s->p == 0)))
	{
		write(1, str, len);
		count += len;
	}
	if (s->flags[MINUS])
		count = print_spaces_x(s, len, count);
	ft_strdel(&str);
	return (count);
}
