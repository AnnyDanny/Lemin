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
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#' && buff[i + 1] != '#')
		{
			return (1);
		}
		else
		{
			return (0);
		}
		i++;
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
			printf("\nants>>>%d\n", s->number_of_ants);
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}

int check_first(int fd, t_s *s, char *buff)
{
	int i;

	i = 0;
	while (get_next_line(fd, &buff) > 0)
	{
		printf("\nbuff>>>%s\n", buff);
		if (check_no_two_hashes(buff) == 1 || (s->number_of_ants == 0 && check_digits_in_str(buff) == 0 && check_comment(buff) == 0))
		{
			printf("\nERROR\n");
			return (1);
		}
		if (check_comment(buff) == 1)
		{
			printf("\ncom\n");
		}
		if (check_right(s, buff) == 1)
		{
			break;
		}
	}
	return (0);
}

int check_start_end(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#' && buff[i + 1] == '#' && buff[i + 2] == 's')
			return (1);
		if (buff[i] == '#' && buff[i + 1] == '#' && buff[i + 2] == 'e')
			return (2);
		i++;
	}
	return (0);
}

int check_count_spaces_start(t_s *s, char *buff)
{
	int i;

	i = 0;
	printf("\niiii1\n");
	printf("\nbuff in space>>>%s\n", buff);
	while (buff[i])
	{
		if (buff[i] == ' ')
		{
			// printf("\niiiii2\n");
			s->spaces++;
			printf("\nbiff[i]>>>%c\n", buff[i]);
		}
		i++;
	}
	// printf("\nspace>>>%d\n", s->spaces);
	if (s->spaces == 2)
		return (1);
	return (0);
}

int check_second(int fd, t_s *s, char *buff)
{
	while(get_next_line(fd, &buff) > 0)
	{
		printf("\nbuff>>>%s\n", buff);
		if (check_start_end(buff) == 1)
		{
			s->start++;
			if (get_start_coord(s, fd, buff) == 0)
			{
				printf("\nERROR\n");
				return (1);
			}
			printf("\nstart>>>%d\n", s->start);
		}
		if (check_start_end(buff) == 2)
		{
			s->end++;
			if (get_end_coord(s, fd, buff) == 0)
			{
				printf("\nERROR\n");
				return (1);
			}
			printf("\nend>>>%d\n", s->end);
		}
	}
	return (0);
}

int main(void)
{
	t_s s;
	char *buff;
	int i;

	i = 0;
	buff = NULL;
	cle_s(&s);
	fd = open("tat", O_RDWR | O_APPEND);
	if (check_first(fd, &s, buff) == 1)
		return (0);
	if (check_second(fd, &s, buff) == 1)
		return (0);
}

