/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_check_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:45:25 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/10 18:45:27 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

void free_m_connect(t_s *s)
{
	ft_strdel(&s->m_connect[0]);
	ft_strdel(&s->m_connect[1]);
}

void check_null_st_en(t_s *s)
{
	if (s->li_start == NULL || s->li_end == NULL)
		error_exit("ERROR");
		// error_exit("error in start end == NULL");
}

void check_double_start(t_s *s, char *buff)
{
	if (s->start == 1)
		error_exit("ERROR");
		// error_exit("double start");
	get_start_coord(s, buff);
	s->start = 1;
}

void check_double_end(t_s *s, char *buff)
{
	if (s->end == 1)
		error_exit("ERROR");
		// error_exit("double end");
	get_end_coord(s, buff);
	s->end = 1;
}

int				check_valid_other_room(t_s *s)
{
	if (s->m[0] != NULL && s->m[0][0] != 'L')
	{
		return (1);
	}
	return (0);
}
