/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 22:05:04 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/26 22:05:04 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

void			check_digits_coord_end(t_s *s)
{
	if (check_valid_end_room(s) == 1 && check_valid_end_x(s) == 1
		&& check_valid_end_y(s) == 1)
	{
		ft_li_add(&s->li, li_new(s->m[0], s->end_x, s->end_y));
		s->li_end = s->li;
	}
	else
		error_exit("111");
}

int				check_count_spaces_end(t_s *s, char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == ' ')
			s->spaces_end++;
		i++;
	}
	if (s->spaces_end == 2)
		return (1);
	return (0);
}

void			get_end_coord(t_s *s, char *buff)
{
	ft_strdel(&buff);
	while (get_next_line(0, &buff) > 0)
	{
		if (check_start_end(buff) == 1 || check_start_end(buff) == 2)
			error_exit("Not exist datas of start/end room or some other error");
		if (buff[0] != '#' && check_count_spaces_end(s, buff) == 1)
		{
			s->m = ft_strsplit(buff, ' ');
			check_digits_coord_end(s);
			ft_strdel(&buff);
			ft_strdel(&s->m[0]);
			ft_strdel(&s->m[1]);
			ft_strdel(&s->m[2]);
			free(s->m);
			return ;
		}
	}
	// ft_strdel(&s->m[0]);
	// ft_strdel(&s->m[1]);
	// ft_strdel(&s->m[2]);
	// free(s->m);
}
