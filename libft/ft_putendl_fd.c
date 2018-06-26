/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:01:20 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/21 20:01:20 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	if (str != NULL)
	{
		while (*str)
			ft_putchar_fd(*str++, fd);
		ft_putchar_fd('\n', fd);
	}
}
