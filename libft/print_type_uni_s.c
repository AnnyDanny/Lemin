/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_uni_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:18:01 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 18:18:02 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					num_bytes(wchar_t *str)
{
	int						len;
	size_t					i;

	len = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] <= 0x7F)
			len++;
		else if (str[i] >= 0x80 && str[i] <= 0x7FF)
			len += 2;
		else if (str[i] >= 0x800 && str[i] <= 0xFFFF)
			len += 3;
		else if (str[i] >= 0x10000 && str[i] <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}

int						p_s(unsigned int c)
{
	if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if (c >= 0x800 && c <= 0xFFFF)
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	return (1);
}

void					no_minus(t_struct *s, int *count)
{
	(s->flags[ZERO]) ? *count = pr_sp_u_s(s, s->l2, *count, '0') : *count;
	(!s->flags[ZERO]) ? *count = pr_sp_u_s(s, s->l2, *count, ' ') : *count;
}

void					yes_minus(t_struct *s, int *count)
{
	(s->flags[ZERO]) ? *count = pr_sp_u_s(s, s->l2, *count, '0') : *count;
	(!s->flags[ZERO]) ? *count = pr_sp_u_s(s, s->l2, *count, ' ') : *count;
}

int						pr_t_u_s(t_struct *s, va_list arg, int count)
{
	s->s2 = va_arg(arg, wchar_t*);
	while (s->s2 && s->s2[s->i] && s->l2 + p_s(s->s2[s->i]) <= s->p)
		s->l2 += p_s(s->s2[s->i++]);
	(s->l2 <= 0) ? s->l2 = num_bytes(s->s2) : s->l2;
	(s->p == 0) ? s->l2 = s->p : s->l2;
	s->i = 0;
	if (s->s2 == NULL)
	{
		ft_putstr("(null)");
		count += ft_strlen("(null)");
	}
	else
	{
		if (s->flags[MINUS] == 0)
			no_minus(s, &count);
		while (s->s2[s->i] && (s->p - p_s(s->s2[s->i]) >= 0 || s->p == -1))
		{
			if (s->p != -1)
				s->p -= p_s(s->s2[s->i]);
			count += print_type_uni_c(s->s2[s->i++], count);
		}
		if (s->flags[MINUS])
			yes_minus(s, &count);
	}
	return (count);
}
