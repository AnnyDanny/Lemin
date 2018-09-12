/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_check_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:32:29 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:32:30 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

int				check_int_other(t_s *s)
{
	if (s->other_y >= -2147483647 && s->other_y <= +2147483647)
		return (1);
	else if (s->other_x >= -2147483647 && s->other_x <= +2147483647)
	{
		ft_printf("\nfirst>>>\n");
		return (1);
	}
	else
		return (0);
}

int				check_valid_other_x(t_s *s)
{
	// if (s->m[1] != NULL && check_digits_in_str(s->m[1]) == 1)
	if (s->m[1] != NULL)
	{
		s->other_x = ft_atoi(s->m[1]);
		// if (s->other_x < 0)
		if (check_int_other(s) == 1)
			return (1);
		// return (0);
	}
	return (0);
}

int				check_valid_other_y(t_s *s)
{
	// if (s->m[2] != NULL && check_digits_in_str(s->m[2]) == 1)
	if (s->m[2] != NULL)
	{
		s->other_y = ft_atoi(s->m[2]);
		// if (s->other_y < 0)
		if (check_int_other(s) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int				exist_dublicate(t_s *s)
{
	t_li *check;

	check = s->li;
	while (check != NULL)
	{
		if (ft_strequ(check->name, s->m[0]) == 1)
			return (0);
		if (check->c_x == s->other_x && check->c_y == s->other_y)
			return (0);
		check = check->next;
	}
	return (1);
}

void			check_digits_coord_other(t_s *s)
{
	if (check_valid_other_room(s) == 1 && check_valid_other_x(s) == 1
		&& check_valid_other_y(s) == 1 && exist_dublicate(s) == 1)
		ft_li_add(&(s->li), li_new(s->m[0], s->other_x, s->other_y));
	else
		error_exit("ERROR");
		// error_exit("Identical room datas or some other error");
}
