/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_x_bx_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:08:21 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 18:08:22 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_hex_len(unsigned long long x, int y)
{
	int						count;

	count = 0;
	if (x == 0)
		return (1);
	while (x >= 1)
	{
		x /= y;
		count++;
	}
	return (count);
}

void				hexa(unsigned long long nbr, int len, char *res)
{
	while (nbr >= 1 && len >= 0)
	{
		if (nbr % 16 >= 10 && nbr % 16 <= 15)
			res[--len] = (nbr % 16) - 10 + 97;
		else if (nbr % 16 < 10)
			res[--len] = (nbr % 16) + 48;
		nbr /= 16;
	}
}

int					check_hash_x(unsigned long long x, t_struct *s, int count)
{
	if (s->flags[HASH] != 0 && x != 0)
	{
		write(1, "0x", 2);
		count += 2;
	}
	return (count);
}

int					check_hash(unsigned long long x, t_struct *s, int count)
{
	if (s->flags[HASH] != 0 && x != 0)
	{
		write(1, "0X", 2);
		count += 2;
	}
	return (count);
}
