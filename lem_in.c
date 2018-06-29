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
#include <stdio.h>
#include "libft/includes/libft.h"

int fd;

void	ft_li_add(t_li **alst, t_li *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_li *li_new(char *number_of_room, int coord_x, int coord_y)
{
	t_li *data;

	if (!(data = (t_li *)malloc(sizeof(t_li))))
		return (NULL);
	data->name = ft_strdup(number_of_room);
	if (!data->name)
	{
		free(data);
		return (NULL);
	}
	data->c_x = coord_x;
	data->c_y = coord_y;
	data->next = NULL;
	return (data);
}

int check_two_hashes(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#' && buff[i + 1] == '#')
			return (1);
		i++;
	}
	return (0);
}

int check_comment(char *buff)
{
	if (buff[0] == '#')
	{
		return (1);
	}
	return (0);
} 

int check_no_two_hashes(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (check_two_hashes(buff) == 1)
			return (1);
		i++;
	}
	return (0);
}

int check_digits_in_str(char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (buff == NULL)
		return (0);
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) == 1)
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int check_right(t_s *s, char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (check_digits_in_str(buff) == 1 && check_comment(buff) == 0)
		{
			s->number_of_ants = ft_atoi(buff);
			if (s->number_of_ants < 0)
				return (0);
			printf("\nants>>>%d\n", s->number_of_ants);
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}

int check_start_end(char *buff)
{
	if (ft_strequ(buff, "##start") == 1)
		return (1);
	if (ft_strequ(buff, "##end") == 1)
		return (2);
	return (0);
}

int check_first(int fd, t_s *s, char *buff)
{
	int i;

	i = 0;
	while (get_next_line(fd, &buff) > 0)
	{
		printf("\nbuff in first>>>%s\n", buff);
		if (check_start_end(buff) != 0)
		{
			printf("\nERROR1\n");
			return (1);
		}
		if (check_right(s, buff) == 1)
		{
			break;
		}
	}
	return (0);
}

int check_second(int fd, t_s *s, char *buff)
{
	while (get_next_line(fd, &buff) > 0)
	{
		printf("\nbuff in second>>>%s\n", buff);
		if (check_start_end(buff) == 1)
		{
			s->s++;
			if (get_start_coord(s, fd, buff) == 0)
			{
				printf("\nERROR3\n");
				return (1);
			}
		}
		if (check_start_end(buff) == 2)
		{
			s->e++;
			if (get_end_coord(s, fd, buff) == 0)
			{
				printf("\nERROR4\n");
				return (1);
			}
		}
	}
	return (0);
}

// int check_third(int fd, char *buff)
// {
// 	while (get_next_line(fd, &buff) > 0)
// 	{
// 		if (check_comment(buff) == 1)
// 			return (1);
// 		else
// 		{
// 			printf("\nERROR\n");
// 			return (0);
// 		}
// 	}
// 	return (0);
// }

int main(void)
{
	t_s s;
	char *buff;
	int i;

	i = 0;
	buff = NULL;
	cle_s(&s);
	// cle_m(&s);
	fd = open("tat", O_RDWR | O_APPEND);
	if (check_first(fd, &s, buff) == 1)
		return (0);
	if (check_second(fd, &s, buff) == 1)
		return (0);
	// printf("\nokokoko1\n");
	ft_strdel(&buff);
	// if (check_third(fd, buff) == 1)
	// {
	// 	printf("\nokokoko2\n");
	// 	return (0);
	// }
}

