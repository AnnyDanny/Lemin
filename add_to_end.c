/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:36:22 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:36:23 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

int check_int_end(t_s *s)
{
	if (s->end_y >= -2147483647 && s->end_y <= +2147483647)
		return (1);
	else if (s->end_x >= -2147483647 && s->end_x <= +2147483647)
		return (1);
	else
		return (0);
}

int				check_first_pos_room_end(char c)
{
	char ch1;

	ch1 = 'L';
	if (c == ch1)
		return (0);
	return (1);
}

int				check_valid_end_room(t_s *s)
{
	int i;

	i = 0;
	if (s->m[0] != NULL && check_first_pos_room_end(s->m[0][0]) == 1)
		return (1);
	return (0);
}

int				check_valid_end_x(t_s *s)
{
	// if (s->m[1] != NULL && check_digits_in_str(s->m[1]) == 1)
	if (s->m[1] != NULL)
	{
		s->end_x = ft_atoi(s->m[1]);
		if (check_int_end(s) == 0)
		// if (s->end_x < 0)
			return (0);
		return (1);
	}
	return (0);
}

int				check_valid_end_y(t_s *s)
{
	// if (s->m[2] != NULL && check_digits_in_str(s->m[2]) == 1)
	if (s->m[2] != NULL)
	{
		s->end_y = ft_atoi(s->m[2]);
		if (check_int_end(s) == 0)
		// if (s->end_y < 0)
			return (0);
		return (1);
	}
	return (0);
}
