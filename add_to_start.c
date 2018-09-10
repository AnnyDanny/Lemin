/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:35:22 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:35:22 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"


int check_int_start(t_s *s)
{
	if (s->start_y >= -2147483647 && s->start_y <= +2147483647)
		return (1);
	else if (s->start_x >= -2147483647 && s->start_x <= +2147483647)
		return (1);
	else
		return (0);
}

int				check_first_pos_room(char c)
{
	char ch1;

	ch1 = 'L';
	if (c == ch1)
		return (0);
	return (1);
}

int				check_valid_start_room(t_s *s)
{
	if (s->m[0] != NULL && check_first_pos_room(s->m[0][0]) == 1)
		return (1);
	return (0);
}

int				check_valid_start_x(t_s *s)
{
	if (s->m[1] != NULL)
	{
		s->start_x = ft_atoi(s->m[1]);
		if (check_int_start(s) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int				check_valid_start_y(t_s *s)
{
	if (s->m[2] != NULL)
	{
		s->start_y = ft_atoi(s->m[2]);
		if (check_int_start(s) == 0)
			return (0);
		return (1);
	}
	return (0);
}
