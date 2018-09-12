/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_coord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 21:18:58 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/26 21:18:59 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

int				check_digits_coord(t_s *s)
{
	if (check_valid_start_room(s) == 1 && check_valid_start_x(s) == 1
		&& check_valid_start_y(s) == 1)
	{
		ft_li_add(&s->li, li_new(s->m[0], s->start_x, s->start_y));
		s->li_start = s->li;
		return (1);
	}
	else
		error_exit("ERROR");
		// error_exit("wrongs with coords");
	return (0);
}

int				check_count_spaces_start(t_s *s, char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == ' ')
			s->spaces_start++;
		i++;
	}
	if (s->spaces_start == 2)
		return (1);
	return (0);
}

void			get_start_coord(t_s *s, char *buff)
{
	t_list *five;

	// ft_strdel(&buff);
	while (get_next_line(0, &buff) > 0)
	{
		five = ft_lstnew(NULL, 0);
		five->content = buff;
		ft_lstadd(&s->print, five);
		if (check_start_end(buff) == 1 || check_start_end(buff) == 2)
			error_exit("ERROR");
			// error_exit("Not exist datas of start/end room or some other error");
		if (buff[0] != '#' && check_count_spaces_start(s, buff) == 1)
		{
			s->m = ft_strsplit(buff, ' ');
			// ft_strdel(&buff);
			check_digits_coord(s);
			ft_strdel(&s->m[0]);
			ft_strdel(&s->m[1]);
			free(s->m[2]);
			free(s->m);
			return ;
		}
		// if (buff[0] == '#')
		// 	ft_strdel(&buff);
		else
		{
			// ft_strdel(&buff);
			error_exit("ERROR");
			// error_exit("no correct datas of start or end");
		}
	}
}
