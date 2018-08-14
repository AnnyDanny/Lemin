/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uni_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:15:51 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/12 18:15:52 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_3_byte(unsigned int c)
{
	char						res[4];
	unsigned int				tmp;

	tmp = c;
	res[0] = (tmp >> 12) | 224;
	tmp = c;
	res[1] = ((tmp >> 6) & 63) | 128;
	tmp = c;
	res[2] = (tmp & 63) | 128;
	res[3] = '\0';
	write(1, res, 3);
	return (3);
}

int						ft_2_byte(unsigned int c)
{
	char						res[3];
	unsigned int				tmp;

	tmp = c;
	res[0] = (tmp >> 6) | 192;
	tmp = c;
	res[1] = (tmp & 63) | 128;
	res[2] = '\0';
	write(1, res, 2);
	return (2);
}

int						ft_4_byte(unsigned int c)
{
	char						res[5];
	unsigned int				tmp;

	tmp = c;
	res[0] = (tmp >> 18) | 240;
	tmp = c;
	res[1] = (tmp >> 12) | 128;
	tmp = c;
	res[2] = (tmp >> 6) | 128;
	tmp = c;
	res[3] = (tmp & 63) | 128;
	res[4] = '\0';
	write(1, res, 4);
	return (4);
}

int						print_type_uni_c(unsigned int c, int count)
{
	int							i;

	i = 0;
	if (MB_CUR_MAX > 1)
	{
		if (c <= 0x7F)
		{
			write(1, &c, 1);
			count = 1;
		}
		else if (c >= 0x80 && c <= 0x7FF)
			count = ft_2_byte(c);
		else if (c >= 0x800 && c <= 0xFFFF)
			count = ft_3_byte(c);
		else if (c >= 0x10000 && c <= 0x10FFFF)
			count = ft_4_byte(c);
	}
	else
	{
		write(1, &c, 1);
		count = 1;
	}
	return (count);
}
