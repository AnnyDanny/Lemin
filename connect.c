/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:25:28 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:25:30 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

t_li			*find_room_if_exist(t_s *s, char *str)
{
	t_li *tmp;

	tmp = s->li;
	while (tmp)
	{
		if (ft_strequ(str, tmp->name) == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void			check_equal_elem(t_s *s)
{
	t_li		*first;
	t_li		*second;
	t_list		*buff;

	first = find_room_if_exist(s, s->m_connect[0]);
	if (first == NULL)
		error_exit("Hyphen in names of room");
	second = find_room_if_exist(s, s->m_connect[1]);
	if (second == NULL)
		error_exit("Error in connections");
	buff = ft_lstnew(NULL, 0);
	buff->content = (void*)second;
	ft_lstadd(&first->connect, buff);
	// free(buff);
	buff = ft_lstnew(NULL, 0);
	buff->content = (void*)first;
	ft_lstadd(&second->connect, buff);
}

int				check_count_hyphen(t_s *s, char *buff)
{
	int i;

	i = 0;
	s->hyphen = 0;
	while (buff[i])
	{
		if (buff[i] == '-')
			s->hyphen++;
		i++;
	}
	if (s->hyphen == 1)
		return (1);
	return (0);
}

int				check_connect(t_s *s, char *buff)
{
	if (s->li_start == NULL || s->li_end == NULL)
		return (0);
	if (check_count_hyphen(s, buff) == 1)
	{
		s->m_connect = ft_strsplit(buff, '-');
		if (s->m_connect[0] != NULL && s->m_connect[1] != NULL)
		{
			check_equal_elem(s);
			ft_strdel(&s->m_connect[0]);
			ft_strdel(&s->m_connect[1]);
			ft_strdel(&s->m_connect[2]);
			free(s->m_connect);
			return (1);
		}
	}
	// ft_strdel(&s->m_connect[0]);
	// ft_strdel(&s->m_connect[1]);
	// ft_strdel(&s->m_connect[2]);
	// free(s->m_connect);
	return (0);
}



// 4
// ##start
// a 5 2
// ##end
// f 5 23
// b 8 9
// c 5 6
// d 3 2
// e 7 3
// a-b
// b-c
// b-d
// c-b
// c-d
// d-c
// d-e
// e-d
// e-f



// 3
// 2 5 0
// ##start
// 0 1 2
// ##end
// 1 9 2
// 3 5 4
// 0-2
// 0-3
// 2-1
// 3-1
// 2-3