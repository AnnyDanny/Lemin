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

void error_exit(char const *str)
{
	printf("\nerror>>>%s\n", str);
	exit(0);
}

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
	// printf("\nokokonew\n");
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
	data->connect = NULL;
	data->check = 0;
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
		// printf("\nbuff in first>>>%s\n", buff);
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

void print_list(t_s *s)
{
	t_li *head1;
	t_li *head2;

	head1 = s->li;
	head2 = s->li_queue_head;
	while (head1 != NULL)
	{
		printf("\nname of other room>>>%s\n", head1->name);
		printf("\nx of other>>>%d\n", head1->c_x);
		printf("\ny of other>>>%d\n", head1->c_y);
		t_list *con1;
		con1 = head1->connect;
		while (con1)
		{
			printf("\nconnect>>>%s\n", ((t_li*)con1->content)->name);
			con1 = con1->next;
		}
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		printf("\nkjkjkjkjkjkkjkjkjkj\n");
		// t_list *con3;
		// con3 = head2->connect;
		// while (con3)
		// {
		// 	printf("\nconnectttttttttt>>>%s\n", ((t_li*)con3->content)->name);
		// 	con3 = con3->next;
		// }
		printf("\ncheckkkkkkkk>>>%d\n", head2->check);
		head2 = head2->next;
	}

}

void print_start_end(t_s *s)
{
	t_li *new_start;
	t_li *new_end;

	new_start = s->li_start;
	while (new_start)
	{
		printf("\nli_start_name>>>%s\n", new_start->name);
		printf("\nli_start_x>>>%d\n", new_start->c_x);
		printf("\nli_start_y>>>%d\n", new_start->c_y);
		t_list *new_con_start;
		new_con_start = new_start->connect;
		while (new_con_start)
		{
			printf("\nnew_con_start>>>%s\n", ((t_li*)new_con_start->content)->name);
			new_con_start = new_con_start->next;
		}
		new_start = new_start->next;
	}
	new_end = s->li_end;
	while (new_end)
	{
		printf("\nli_end_name>>>%s\n", new_end->name);
		printf("\nli_end_x>>>%d\n", new_end->c_x);
		printf("\nli_end_y>>>%d\n", new_end->c_y);
		t_list *new_con_end;
		new_con_end = new_end->connect;
		while (new_con_end)
		{
			printf("\nnew_con_end>>>%s\n", ((t_li*)new_con_end->content)->name);
			new_con_end = new_con_end->next;
		}
		new_end = new_end->next;
	}
}

int check_second(int fd, t_s *s, char *buff)
{
	while (get_next_line(fd, &buff) > 0)
	{
		if (check_other_coords(s, buff) == 0)
		{
			if (check_connect(s, buff) == 0)
			{
				if (check_start_end(buff) == 1)
				{
					if (get_start_coord(s, fd, buff) == 0)
					{
						printf("\nERROR3\n");
						return (1);
					}
					else 
						s->s++;
				}
				else if (check_start_end(buff) == 2)
				{
					if (get_end_coord(s, fd, buff) == 0)
					{
						printf("\nERROR4\n");
						return (1);
					}
					else
						s->e++;
				}
			}
		}
		printf("\nbuff in second>>>%s\n", buff);
	}
	t_list *find;

	find = s->li_start->connect;
	create_queue(s, find);
	find_best_way(s);
	// print_list(s);
	// print_start_end(s);
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
	// cle_m(&s);
	// cle_m_dash(&s);
	fd = open("tat", O_RDWR | O_APPEND);
	if (check_first(fd, &s, buff) == 1)
		return (0);
	if (check_second(fd, &s, buff) == 1)
		return (0);
	ft_strdel(&buff);
}

