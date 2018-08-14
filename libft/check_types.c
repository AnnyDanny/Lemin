/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 02:31:46 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/07 02:31:47 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		check_types2(t_struct *s, va_list arg, int *count)
{
	if (s->sp == 'u' || s->sp == 'U')
		*count = print_type_u(s, arg, *count);
	else if (s->sp == 'x')
		*count = print_type_x(s, arg, *count);
	else if (s->sp == 'p')
		*count = print_hexa_p(s, arg, *count);
	else if (s->sp == 'X')
		*count = print_type_uni_x(s, arg, *count);
}

int			check_types(t_struct *s, va_list arg, int count)
{
	unsigned int c;

	if (s->sp == 'C' && MB_CUR_MAX == 4)
	{
		c = va_arg(arg, unsigned int);
		count = print_type_uni_c(c, count);
	}
	else if ((s->sp == 'S' || (s->sp == 's' && s->flags[L] == 1)))
	{
		count = pr_t_u_s(s, arg, count);
		if (MB_CUR_MAX != 4)
			return (-1);
	}
	else if (s->sp == 's' && !s->flags[L])
		count = print_type_s(s, arg, count);
	else if (s->sp == 'd' || s->sp == 'i' || s->sp == 'D')
		count = check_all_d_i_bd(s, arg, count);
	else if (s->sp == 'c' || s->sp == 37 || s->sp == 'C')
		count = print_type_c(s, arg, count);
	else if (s->sp == 'o' || s->sp == 'O')
		count = print_type_o(s, arg, count);
	else
		check_types2(s, arg, &count);
	return (count);
}
