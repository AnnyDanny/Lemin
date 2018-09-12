/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other_coord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:28:55 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/29 16:28:56 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

int				check_count_spaces_other(t_s *s, char *buff)
{
	int i;

	i = 0;
	s->spaces_other = 0;
	while (buff[i])
	{
		if (buff[i] == ' ')
			s->spaces_other++;
		i++;
	}
	if (s->spaces_other == 2)
		return (1);
	return (0);
}

void			check_other_coords(t_s *s, char *buff)
{
	if (check_count_spaces_other(s, buff) == 1)
	{
		s->m = ft_strsplit(buff, ' ');
		check_digits_coord_other(s);
		ft_strdel(&s->m[0]);
		ft_strdel(&s->m[1]);
		ft_strdel(&s->m[2]);
		free(s->m);
		// ft_strdel(&buff);
	}
	else
		error_exit("ERROR");
		// error_exit("Error with validation in datas of room");
}
