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
		if (check_count_spaces(s, buff) == 1)
		{
			s->m = ft_strsplit(buff, ' ');
			if (check_digits_coord(s) == 1)
			{
				printf("\nroom>>>%s\n", s->number_of_room);
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