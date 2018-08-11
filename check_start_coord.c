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
#include <stdio.h>
#include "libft/includes/libft.h"

int check_first_pos_room(char c)
{
	char ch1;

	ch1 = 'L';
	if (c == ch1)
		return (0);
	return (1);
}

int check_valid_start_room(t_s *s)
{
	if (s->m[0] != NULL && check_first_pos_room(s->m[0][0]) == 1)
		return (1);
	return (0);
}

int check_valid_start_x(t_s *s)
{
	if (check_digits_in_str(s->m[1]) == 1 && s->m[1] != NULL)
	{
		s->start_x = ft_atoi(s->m[1]);
		if (s->start_x < 0)
			return (0);
		return (1);
	}
	return (0);
}

int check_valid_start_y(t_s *s)
{
	if (check_digits_in_str(s->m[2]) == 1 && s->m[2] != NULL)
	{
		s->start_y = ft_atoi(s->m[2]);
		if (s->start_y < 0)
			return (0);
		return (1);
	}
	return (0);
}

int check_digits_coord(t_s *s)
{
	if (check_valid_start_room(s) == 1 && check_valid_start_x(s) == 1 && check_valid_start_y(s) == 1)
	{
		ft_li_add(&s->li, li_new(s->m[0], s->start_x, s->start_y));
		s->li_start = s->li;
		return (1);
	}
	return (0);
}

int check_count_spaces_start(t_s *s, char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == ' ')
		{
			s->spaces_start++;
		}
		i++;
	}
	if (s->spaces_start == 2)
		return (1);
	return (0);
}

void get_start_coord(t_s *s, int fd, char *buff)
{
	while (get_next_line(fd, &buff) > 0)
	{
		if (check_start_end(buff) == 1 || check_start_end(buff) == 2)
			error_exit("error_exit in get_end_coord 1");
		if (buff[0] != '#' && check_count_spaces_start(s, buff) == 1)
		{
			s->m = ft_strsplit(buff, ' ');
			check_digits_coord(s);
			return ;
		}
	}
}