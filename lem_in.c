/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 02:26:55 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/23 02:26:56 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

int				check_first(t_s *s, char *buff)
{
	while (get_next_line(0, &buff) > 0)
	{
		if (check_start_end(buff) != 0)
		{
			error_exit("First line is not a number of ants");
			return (1);
		}
		else if (check_comment(buff) == 1)
		{
			ft_strdel(&buff);
			continue ;
		}
		else if (check_right(s, buff) == 1)
			break ;
		else
		{
			error_exit("Not enough datas of ants or some other error");
			return (1);
		}
	}
	return (0);
}

void			check_second(t_s *s, char *buff)
{
	while (get_next_line(0, &buff) > 0)
	{
		if (check_start_end(buff) == 1)
		{
			if (s->start == 1)
				error_exit("double start");
			get_start_coord(s, buff);
			s->start = 1;
		}
		else if (check_start_end(buff) == 2)
		{
			if (s->end == 1)
				error_exit("double end");
			get_end_coord(s, buff);
			s->end = 1;
		}
		else if (buff[0] != '#' && ft_strchr(buff, '-') != NULL)
		{
			if (check_connect(s, buff) == 0)
			{
				error_exit("Some errors with connections");
			}
			else
			{
				ft_strdel(&s->m_connect[0]);
				ft_strdel(&s->m_connect[1]);
				ft_strdel(&buff);
			}
			break ;
		}
		else if (buff[0] != '#')
			check_other_coords(s, buff);
	}
	if (s->li_start == NULL || s->li_end == NULL)
		error_exit("error in start end == NULL");
}

void			check_third(t_s *s, char *buff)
{
	while (get_next_line(0, &buff) > 0)
	{
		if (check_start_end(buff) == 1 || check_start_end(buff) == 2)
			error_exit("error in check_third 1");
		else if (buff[0] != '#')
		{
			if (check_connect(s, buff) == 0)
			{
				ft_strdel(&buff);
				error_exit("error in check_connect 2");
			}
			ft_strdel(&buff);
		}
	}
	ft_strdel(&buff);
}

int additional_verification(t_s *s)
{
	if (s->li->connect == NULL)
		return (1);
	if (s->li_start->connect == NULL)
		return (1);
	if (s->li_end->connect == NULL)
		return (1);
	return (0);
}

int				main(void)
{
	t_s			s;
	char		*buff;
	int			i;

	i = 0;
	buff = NULL;
	cle_s(&s);
	if (check_first(&s, buff) == 1)
		return (0);
	check_second(&s, buff);
	check_third(&s, buff);
	if (additional_verification(&s) == 1)
		error_exit("connects are no exist");
	create_queue(&s);
	from_end(&s);
	go_ants(&s);
	system("leaks lem-in");
}
// просто вводить в терминале и запустить программу, но для этого сначала скачать питон
// export MallocStackLogging=YES

// 10
// ##start
// 1 1 1
// ##end
// 9 2 2
// 2 3 3
// 3 5 5
// 4 4 4
// 5 6 6
// 6 7 7
// 7 8 8
// 8 9 9
// 10 10 10
// 11 11 11
// 11-4
// 1-4
// 1-3
// 1-2
// 2-6
// 2-3
// 3-4
// 4-10
// 10-8
// 10-9
// 3-8
// 8-9
// 2-8
// 2-9
// 2-5
// 5-7
// 7-9

// 4
// ##start
// a 5 2
// ##end
// f 5 23
// b 8 9
// c 5 6
// kkk 8 6
// d 3 2
// w 6 5
// e 7 3
// yyy 5 5
// iii 9 8
// a-b
// b-c
// c-kkk
// kkk-d
// b-d
// c-b
// c-d
// d-c
// d-e
// d-w
// w-e
// e-d
// e-f
// e-yyy
// yyy-iii