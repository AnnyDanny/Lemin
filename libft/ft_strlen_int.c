/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 02:34:07 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/07 02:34:07 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int					ft_strlen_int(int num)
{
	char			*s;
	int				i;

	s = NULL;
	i = 0;
	s = ft_itoa(num);
	while (s && s[i])
		i++;
	ft_strdel(&s);
	return (i);
}
