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
#include <stdio.h>
#include "libft/includes/libft.h"


int check_first_pos_room_end(char c)
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

int check_valid_end_room(t_s *s)
{
	int i;

	i = 0;
	if ((ft_isdigit(s->m[0][i]) == 1 && s->m[0] != NULL && check_first_pos_room_end(s->m[0][0]) == 1) ||
		(ft_isalpha(s->m[0][i]) == 1 && s->m[0] != NULL && check_first_pos_room_end(s->m[0][0]) == 1))
	{
		// s->number_of_room_end = s->m[0];
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_valid_end_x(t_s *s)
{
	if (check_digits_in_str(s->m[1]) == 1 && s->m[1] != NULL)
	{
		s->end_x = ft_atoi(s->m[1]);
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_valid_end_y(t_s *s)
{
	if (check_digits_in_str(s->m[2]) == 1 && s->m[2] != NULL)
	{
		s->end_y = ft_atoi(s->m[2]);
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_digits_coord_end(t_s *s)
{
	t_li *li2;

	if (check_valid_end_room(s) == 1 && check_valid_end_x(s) == 1 && check_valid_end_y(s) == 1)
	{
		ft_li_add(&s->li, li_new(s->m[0], s->end_x, s->end_y));
		li2 = s->li;
		s->li_end = s->li;
		// while (li2)
		// {
			printf("\nname of end room>>>%s\n", li2->name);
			printf("\nx of end room>>>%d\n", li2->c_x);
			printf("\ny of end room>>>%d\n", li2->c_y);
			// li2 = li2->next;
		// }
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_count_spaces_end(t_s *s, char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == ' ')
		{
			s->spaces_end++;
		}
		i++;
	}
	if (s->spaces_end == 2)
		return (1);
	return (0);
}

int get_end_coord(t_s *s, int fd, char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	get_next_line(fd, &buff);
	while (buff[i])
	{
		if (check_count_spaces_end(s, buff) == 1)
		{
			s->m = ft_strsplit(buff, ' ');
			if (check_digits_coord_end(s) == 1)
			{
				// printf("\nroom_end>>>%s\n", s->number_of_room_end);
				// printf("\nx_end>>>%d\n", s->end_x);
				// printf("\ny_end>>>%d\n", s->end_y);
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (0);
}
