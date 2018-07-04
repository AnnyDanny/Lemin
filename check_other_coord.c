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
#include <stdio.h>
#include "libft/includes/libft.h"


int check_valid_other_room(t_s *s)
{
	int i;

	i = 0;
	if ((ft_isdigit(s->m[0][i]) == 1 && s->m[0] != NULL && check_first_pos_room(s->m[0][0]) == 1) ||
		(ft_isalpha(s->m[0][i]) == 1 && s->m[0] != NULL && check_first_pos_room(s->m[0][0]) == 1))
	{
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_valid_other_x(t_s *s)
{
	if (check_digits_in_str(s->m[1]) == 1 && s->m[1] != NULL)
	{
		s->other_x = ft_atoi(s->m[1]);
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_valid_other_y(t_s *s)
{
	if (check_digits_in_str(s->m[2]) == 1 && s->m[2] != NULL)
	{
		s->other_y = ft_atoi(s->m[2]);
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_digits_coord_other(t_s *s)
{
	t_li *li3;
	// t_li *head2;

	// t_li *head;
	// printf("\nokokokokokkoko\n");
	// li3 = s->li;
	// while (s->li)
	// {
		// printf("\nname of other room>>>%s\n", li3->name);
		// printf("\nx of other>>>%d\n", li3->c_x);
		// printf("\ny of other>>>%d\n", li3->c_y);
	// 	s->li_other = s->li_other->next;
	// }

	if (check_valid_other_room(s) == 1 && check_valid_other_x(s) == 1 && check_valid_other_y(s) == 1)
	{
		// printf("\n nameeeee>>>>%s\n", s->m[0]);
		// printf("\n otherxxxxxx>>>>%d\n", s->other_x);
		// printf("\n otheryyyyy>>>>%d\n", s->other_y);
		// printf("\nokok333\n");
		if (s->head == NULL)
		{
			// printf("\nokokok111\n");
			s->head = li_new(s->m[0], s->other_x, s->other_y);
			// printf("\nokokok444\n");
		}
		else
		{

			ft_li_add(&(s->head), li_new(s->m[0], s->other_x, s->other_y));
			// printf("\nokokok222\n");
		}
		// head = li_new(s->m[0], s->other_x, s->other_y);
		// ft_li_add(&head, li_new(s->m[0], s->other_x, s->other_y));
		li3 = s->head;
		// s->li_other = s->li;
		// s->li_other = s->li;
		// while (s->li_other)
		// {
			// printf("\nname of other room>>>%s\n", li3->name);
			// printf("\nx of other>>>%d\n", li3->c_x);
			// printf("\ny of other>>>%d\n", li3->c_y);
		// 	s->li_other = s->li_other->next;
		// }
		// while (s->li)
		// {
		// 	ft_li_add(&s->li, li_new(s->m[0], s->other_x, s->other_y));
		// 	s->li = s->li->next;
		// }
		// li3 = s->li;
		// s->li_other = s->li;
		// while (s->li_other)
		// {
		// 	printf("\nname of other room>>>%s\n", s->li_other->name);
		// 	printf("\nx of other>>>%d\n", s->li_other->c_x);
		// 	printf("\ny of other>>>%d\n", s->li_other->c_y);
		// 	s->li_other = s->li_other->next;
		// }
		return (1);
	}
	else
		return (0);
	return (0);
}

int check_count_spaces_other(t_s *s, char *buff)
{
	int i;

	i = 0;
	s->spaces_other = 0;
	while (buff[i])
	{
		if (buff[i] == ' ')
		{
			s->spaces_other++;
		}
		i++;
	}
	// printf("\ncount spaces in other>>>%d\n", s->spaces_other);
	if (s->spaces_other == 2)
	{
		// printf("\n ok count spaces\n");
		return (1);
	}
	return (0);
}

int check_other_coords(t_s *s, char *buff)
{
	// printf("\nokokok1\n");
	// printf("\nbuff in other>>>%s\n", buff);
	// if (check_two_hashes(buff) == 0)
	// {
		if (check_count_spaces_other(s, buff) == 1 && check_comment(buff) == 0)
		{
		// printf("\nokokok2\n");
			s->m = ft_strsplit(buff, ' ');
			// printf("\nmmmmmm>>>%s\n", s->m[0]);
			if (check_digits_coord_other(s) == 1)
			{
			// printf("\nokokok3\n");
				return (1);
			}
			else
			{
			// printf("\nokokok4\n");
				return (0);
			}
		}
	// }
	return (0);
}