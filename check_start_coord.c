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
		s->number_of_room_start = s->m[0];
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
		s->start_x = s->m[1];
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
		s->start_y = s->m[2];
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_digits_coord(t_s *s)
{
	if (check_valid_start_room(s) == 1 && check_valid_start_x(s) == 1 && check_valid_start_y(s) == 1)
	{
		return (1);
	}
	else
		return (0);
	return (0);
}

int get_start_coord(t_s *s, int fd, char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	cle_m(s);
	get_next_line(fd, &buff);
	while (buff[i])
	{
		if (check_count_spaces_start(s, buff) == 1)
		{
			s->m = ft_strsplit(buff, ' ');
			if (check_digits_coord(s) == 1)
			{
				printf("\nroom>>>%s\n", s->number_of_room_start);
				printf("\nx>>>%s\n", s->start_x);
				printf("\ny>>>%s\n", s->start_y);
				return (1);
			}
			else
				return (0);
			printf("\nbuff in get>>%s\n", buff);
		}
		i++;
	}
	return (0);
}

int check_count_spaces_end(t_s *s, char *buff)
{
	int i;

	i = 0;
	printf("\niiii1\n");
	printf("\nbuff in space>>>%s\n", buff);
	while (buff[i])
	{
		if (buff[i] == ' ')
		{
			// printf("\niiiii2\n");
			s->spaces++;
			printf("\nbiff[i]>>>%c\n", buff[i]);
		}
		i++;
	}
	// printf("\nspace>>>%d\n", s->spaces);
	if (s->spaces == 2)
		return (1);
	return (0);
}

// int get_end_coord(t_s *s, int fd, char *buff)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	cle_m(s);
// 	ft_strdel(&buff);
// 	get_next_line(fd, &buff);
// 	// printf("\nbuff in end>>>%s\n", buff);
// 	while (buff[i])
// 	{
// 		// printf("\nlklklk1\n");
// 		if (check_count_spaces_end(s, buff) == 1)
// 		{
// 			// printf("\nlklklk2\n");
// 			s->m = ft_strsplit(buff, ' ');
// 			if (check_digits_coord(s) == 1)
// 			{
// 				printf("\nroom>>>%s\n", s->number_of_room);
// 				printf("\nx>>>%s\n", s->start_x);
// 				printf("\ny>>>%s\n", s->start_y);
// 				return (1);
// 			}
// 			else
// 				return (0);
// 			printf("\nbuff in get>>%s\n", buff);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int get_end_coord(t_s *s, int fd, char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	cle_m(s);
	get_next_line(fd, &buff);
	while (buff[i])
	{
		if (check_count_spaces_end(s, buff) == 1)
		{
			s->m = ft_strsplit(buff, ' ');
			if (check_digits_coord(s) == 1)
			{
				printf("\nroom>>>%s\n", s->number_of_room_end);
				printf("\nx>>>%s\n", s->end_x);
				printf("\ny>>>%s\n", s->end_y);
				return (1);
			}
			else
				return (0);
			printf("\nbuff in get>>%s\n", buff);
		}
		i++;
	}
	return (0);
}

