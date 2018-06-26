/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cle_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:35:32 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/23 16:35:34 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		cle_s(t_s *s)
{
	s->number_of_ants = 0;
	s->number_of_room = NULL;
	s->comment = 0;
	s->two_hash = 0;
	s->start = 0;
	s->end = 0;
	s->check_number = NULL;
	s->i = 0;
	s->check = 0;
	s->spaces = 0;
	s->start_x = NULL;
	s->start_y = NULL;
	s->number_of_room_end = NULL;
	s->end_x = NULL;
	s->end_y = NULL;
}

void cle_m(t_s *s)
{
	int i;
	// int j;

	i = 0;
	// j = 0;
	while (s->m[i])
	{
		s->m[i] = NULL;
		i++;
	}
}