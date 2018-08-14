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
			get_start_coord(s, buff);
		else if (check_start_end(buff) == 2)
			get_end_coord(s, buff);
		else if (buff[0] != '#' && ft_strchr(buff, '-') != NULL)
		{
			if (check_connect(s, buff) == 0)
				error_exit("Some errors with connections");
			break ;
		}
		else if (buff[0] != '#')
			check_other_coords(s, buff);
	}
	if (s->li_start == NULL || s->li_end == NULL)
	{
		error_exit("error in start end == NULL");
	}
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
				error_exit("error in check_connect 2");
		}
	}
	ft_strdel(&buff);
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
	create_queue(&s);
	from_end(&s);
	go_ants(&s);
	// system("leaks lem-in");
}
