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

	if (check_valid_other_room(s) == 1 && check_valid_other_x(s) == 1 && check_valid_other_y(s) == 1)
	{
		// if (s->head == NULL)
		// {
		// 	s->head = li_new(s->m[0], s->other_x, s->other_y);
		// }
		// else
		{
			ft_li_add(&(s->li), li_new(s->m[0], s->other_x, s->other_y));
		}
		li3 = s->li;
		return (1);
	}
	else
		return (0);
	return (0);
}

t_li *find_room_if_exist(t_s *s, char *str)
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

void check_equal_elem(t_s *s)
{
	t_li *first;
	t_li *second;
	t_list *buff;

	// printf("\nwhat is m_connect[0]>>>%s\n", s->m_connect[0]);
	first = find_room_if_exist(s, s->m_connect[0]);
	if (first == NULL)
	{
		error_exit("first connect");
	}
	// printf("\nwhat is m_connect[1]>>>%s\n", s->m_connect[1]);
	second = find_room_if_exist(s, s->m_connect[1]);
	if (second == NULL)
	{
		error_exit("second connect");
	}
	buff = ft_lstnew(NULL, 0);
	buff->content = (void*)second;
	ft_lstadd(&first->connect, buff);
	buff = ft_lstnew(NULL, 0);
	buff->content = (void*)first;
	ft_lstadd(&second->connect, buff);
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
	if (s->spaces_other == 2)
		return (1);
	return (0);
}

int check_other_coords(t_s *s, char *buff)
{
		if (check_count_spaces_other(s, buff) == 1 && check_comment(buff) == 0)
		{
			s->m = ft_strsplit(buff, ' ');
			if (check_digits_coord_other(s) == 1)
				return (1);
			else
				return (0);
		}
	return (0);
}

int check_count_dash(t_s *s, char *buff)
{
	int i;

	i = 0;
	s->dash = 0;
	while (buff[i])
	{
		if (buff[i] == '-')
		{
			s->dash++;
		}
		i++;
	}
	if (s->dash == 1)
		return (1);
	return (0);
}

void try_add(t_s *s)
{
	t_list *queue_head;
	t_list *queue_tail;
	t_list *conn;

	queue_head = ft_lstnew(NULL, 0);
	queue_head->content = s->li_start;
	queue_tail = queue_head;
	s->li_start->check = 1;
	while (queue_head != NULL)
	{
		printf("\n\nok in first while in try_add\n\n");
		conn = ((t_li*)queue_head->content)->connect;
		while (conn != NULL)
		{
			// printf("\n\nok in second while in try_add\n\n");
			// while (conn != NULL)
			// {
			// 	printf("\nconn and check in try_add>>>%d\n", ((t_li*)conn->content)->check);
			// 	conn = conn->next;
			// }
			if (((t_li*)conn->content)->check == 0)
			{
				printf("\n\nok in first if in try_add\n\n");
				((t_li *)conn->content)->check = ((t_li*)queue_head->content)->check + 1;
				t_list *buff;
				buff = ft_lstnew(NULL, 0);
				buff->content = conn->content;
				queue_tail->next = buff;
				queue_tail = queue_tail->next;
			}
			conn = conn->next;
		}
		queue_head = queue_head->next;
	}
	t_li *print_head;

	print_head = s->li;
	while (print_head != NULL)
	{
		printf("\nname of room>>>%s\ncheck>>>%d\n", print_head->name, print_head->check);
		print_head = print_head->next;
	}
}


// interrupt "exit"

// debager:
// 1. in Makefile exclude flag "g"
// 2. lldb and gdb its debagers
// 3. breakpoint and name of func
// Причины сегментации
// Наиболее распространенные причины ошибки сегментации:
// Разыменование нулевых указателей 
// Попытка доступа к несуществующему адресу памяти (за пределами адресного пространства процесса)
// Попытка доступа к памяти программой, которая не имеет права на эту часть памяти
// Попытка записи в память, предназначенной только для чтения
// Причины зачастую вызваны ошибками программирования, которые приводят к ошибкам связанными с памятью:
// Создание операций с разыменованым указателем или создание неинициализированного указателя (указатель, который указывает на случайный адрес памяти)
// Разыменование или возложение на освобожденной указатель (использование оборванного указателя, который указывает на память, которая была освобождена или перераспределена).
// Переполнение буфера
// Переполнение стека
// Попытка выполнить программу, которая не компилируется правильно. (Некоторые компиляторы будут выводить исполняемый файл , несмотря на наличие ошибок во время компиляции.)


// Можно сразу сделать  tail->next = ft_lstnew(NULL, 0);
//        tail->next->content = conn->content;
//        tail = tail->next;
// Создали новый элемент, добавили его в конец списка. 
// После этого тэил указывает на предпоследний элемент, 
// так как только что добавился один элемент.
//  Нам надо, чтобы тэил всегда указывал на конец. 
//  Поэтому мы его сдвигаем на один элемент вперед.

// our conn have point on lists with rooms and have check!
// void try_add(t_s *s)
// {
//    t_list *queue_head;
//    t_list *queue_tail;
//    t_list *conn;    queue_head = ft_lstnew(NULL, 0);
//    queue_tail = ft_lstnew(NULL, 0);
//    queue_head->content = s->li_start;
//    queue_tail->content = s->li_start;
//    while (queue_head != NULL)
//    {
//     conn = ((t_li*)quene_head->content)->connect;
//        while (conn != NULL)
//        {
//            if (((t_li *)conn->content)->check != 0)
//            {
//                ((t_li *)conn->content)->check = ((t_li*)quene_head->content)->check + 1;
//					t_list buf = ft_lstnew(NULL, 0);
//         			buf->content = conn->content;
//         			tail->next = buf;
//         			tail = tail->next;
//            }
//            conn = conn->next;
//        }
//        queue_head = queue_head->next;
//    }
// }

// И в ифе проверяй не родительский чек каждый раз а коннекта
// Ты же связи проверяешь а не родителя
// И добавляй в очередь после того, как чек изменишь
// в этом же ифе
// ((t_li*)queue_head->content)->check
// conn = ((t_li)head->content)->connect;

int check_connect(t_s *s, char *buff)
{
	if (check_count_dash(s, buff) == 1 && check_comment(buff) == 0)
	{
		s->m_connect = ft_strsplit(buff, '-');
		if (s->m_connect[0] != NULL && s->m_connect[1] != NULL)
		{
			check_equal_elem(s);
		}
		else
			error_exit("null in m_connect");
	}
	else
	{
		return (0);
	}
	return (0);
}