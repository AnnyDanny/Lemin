/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:29:51 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:29:52 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

void			from_end(t_s *s)
{
	t_list		*find_end;
	int			check;
	t_list		*new;

	find_end = s->li_end->connect;
	check = s->li_end->check;
	s->shortest = ft_lstnew(NULL, 0);
	s->shortest->content = s->li_end;
	while (find_end != NULL)
	{
		if (check == ((t_li*)find_end->content)->check + 1)
		{
			new = ft_lstnew(find_end->content, 0);
			new->content = find_end->content;
			ft_lstadd(&s->shortest, new);
			find_end = ((t_li*)find_end->content)->connect;
			check--;
			if (check == 2)
				break ;
		}
		else
			find_end = find_end->next;
	}
}

void			create_queue(t_s *s)
{
	t_list *q;
	t_list *conn;

	q = ft_lstnew(NULL, 0);
	q->content = s->li_start;
	s->queue_tail = q;
	s->li_start->check = 1;
	while (q != NULL)
	{
		conn = ((t_li*)q->content)->connect;
		while (conn != NULL)
		{
			if (((t_li*)conn->content)->check == 0)
			{
				((t_li *)conn->content)->check = ((t_li*)q->content)->check + 1;
				s->buff = ft_lstnew(NULL, 0);
				s->buff->content = conn->content;
				s->queue_tail->next = s->buff;
				s->queue_tail = s->queue_tail->next;
			}
			conn = conn->next;
		}
		q = q->next;
	}
}
