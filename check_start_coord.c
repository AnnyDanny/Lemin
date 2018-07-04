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
	int i;
	char ch1;
	char ch2;

	i = 0;
	ch1 = 'L';
	ch2 = '#';
	if (c == ch1 || c == ch2)
		return (0);
	else
		return (1);
	return (0);
}

int check_valid_start_room(t_s *s)
{
	int i;

	i = 0;
	if ((ft_isdigit(s->m[0][i]) == 1 && s->m[0] != NULL && check_first_pos_room(s->m[0][0]) == 1) ||
		(ft_isalpha(s->m[0][i]) == 1 && s->m[0] != NULL && check_first_pos_room(s->m[0][0]) == 1))
	{
		// s->number_of_room_start = s->m[0];
		// s->buff1 = s->m[0];
		// printf("\nbuff1>>>%s\n", s->buff1);
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_valid_start_x(t_s *s)
{
	if (check_digits_in_str(s->m[1]) == 1 && s->m[1] != NULL)
	{
		s->start_x = ft_atoi(s->m[1]);
		// s->start_x = s->m[1];
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_valid_start_y(t_s *s)
{
	if (check_digits_in_str(s->m[2]) == 1 && s->m[2] != NULL)
	{
		s->start_y = ft_atoi(s->m[2]);
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_digits_coord(t_s *s)
{
	t_li *li1;

	if (check_valid_start_room(s) == 1 && check_valid_start_x(s) == 1 && check_valid_start_y(s) == 1)
	{
		ft_li_add(&s->li, li_new(s->m[0], s->start_x, s->start_y));
		li1 = s->li;
		s->li_start = s->li;
		// while (li1)
		// {
			printf("\nname of start room>>>%s\n", li1->name);
			printf("\nx of start room>>>%d\n", li1->c_x);
			printf("\ny of start room>>>%d\n", li1->c_y);
			li1 = li1->next;
		// }
		return (1);
	}
	else
		return (0);
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

int get_start_coord(t_s *s, int fd, char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	get_next_line(fd, &buff);
	while (buff[i])
	{
		if (check_count_spaces_start(s, buff) == 1 && check_comment(buff) == 0)
		{
			s->m = ft_strsplit(buff, ' ');
			if (check_digits_coord(s) == 1)
			{
				// printf("\nroom_start>>>%s\n", s->number_of_room_start);
				// printf("\nx_start>>>%s\n", s->start_x);
				// printf("\ny_start>>>%s\n", s->start_y);
				return (1);
			}
			else
				return (0);
			printf("\nbuff in get_start>>%s\n", buff);
		}
		i++;
	}
	return (0);
}