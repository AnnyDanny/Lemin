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
	if (s->m[0] != NULL && s->m[0][0] != 'L')
		return (1);
	return (0);
}

int check_valid_other_x(t_s *s)
{
	if (s->m[1] != NULL && check_digits_in_str(s->m[1]) == 1)
	{
		s->other_x = ft_atoi(s->m[1]);
		if (s->other_x < 0)
			return (0);
		return (1);
	}
	return (0);
}

int check_valid_other_y(t_s *s)
{
	if (s->m[2] != NULL && check_digits_in_str(s->m[2]) == 1)
	{
		s->other_y = ft_atoi(s->m[2]);
		if (s->other_y < 0)
			return (0);
		return (1);
	}
	return (0);
}

int exist_dublicate(t_s *s)
{
	t_li *check;

	check = s->li;
	while (check != NULL)
	{
		if (ft_strequ(check->name, s->m[0]) == 1)
			return (0);
		if (check->c_x == s->other_x && check->c_y == s->other_y)
			return (0);
		check = check->next;
	}
	return (1);
}

void check_digits_coord_other(t_s *s)
{
	if (check_valid_other_room(s) == 1 && check_valid_other_x(s) == 1 && check_valid_other_y(s) == 1 && exist_dublicate(s) == 1)
		ft_li_add(&(s->li), li_new(s->m[0], s->other_x, s->other_y));
	else
		error_exit("error in check_digits_coord_other");
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

	first = find_room_if_exist(s, s->m_connect[0]);
	if (first == NULL)
	{
		error_exit("first connect");
	}
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
			s->spaces_other++;
		i++;
	}
	if (s->spaces_other == 2)
		return (1);
	return (0);
}

void check_other_coords(t_s *s, char *buff)
{
	if (check_count_spaces_other(s, buff) == 1)
	{
		s->m = ft_strsplit(buff, ' ');
		check_digits_coord_other(s);
	}
	else
		error_exit("error on check_other_coords");
}

int check_count_hyphen(t_s *s, char *buff)
{
	int i;

	i = 0;
	s->hyphen = 0;
	while (buff[i])
	{
		if (buff[i] == '-')
		{
			s->hyphen++;
		}
		i++;
	}
	if (s->hyphen == 1)
		return (1);
	return (0);
}

void from_end(t_s *s)
{
	t_list *find_end;
	int check;
	t_list *new;

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
				break;
		}
		else
			find_end = find_end->next;
	}
	t_list *sho;

	sho = s->shortest;
	while (sho != NULL)
	{
		printf("\nname of shortest>>>%s\n", ((t_li*)sho->content)->name);
		sho = sho->next;
	}
}


// `new = (void*)find_end->content;` change it to `new->content = find_end->content;`

// void from_end(t_s *s)
// {
//    t_list *find_end;
//    int check;
//    t_list *new; 

// find_end = s->li_end->connect;
//    check = s->li_end->check;
//    s->shortest = ft_lstnew(NULL, 0);
//    s->shortest->content = s->li_end;
//    while (find_end != NULL)
//    {
//        if (check == ((t_li*)find_end->content)->check + 1)
//        {
//            new = ft_lstnew(find_end->content, 0);
//            new = (void*)find_end->content;
//            ft_lstadd(&s->shortest, new);
//            find_end = ((t_li*)find_end->content)->connect;
//            check--;
//         if (check == 2)
//         break;
//        }
//        else
//            find_end = find_end->next;
//    }
// }

// find_end = s->shortest; 
// - find_end =  ((t_li*)find_end->content)->connect;
// s->shortest = ft_lstnew(NULL, 0); 
// after this line add `s->shortest->content = s->li_end;`
// check--; 
// after this line add if (check == 2) break;


void create_queue(t_s *s)
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
	if (s->li_end->check == 0)
		error_exit("there are no any paths");
}

t_list *get_end_room(t_s *s)
{
	t_list *tmp;

	tmp = s->shortest;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void func(t_list *ants, int current_ants)
{
	if (ants == NULL)
		return ;
	func(ants->next, ants->content_size);
	if (current_ants != 0)
	{
		printf("L%d-%s ", current_ants, ((t_li*)ants->content)->name);
	}
	ants->content_size = current_ants;
}

void go_ants(t_s *s)
{
	t_list *ants;
	t_list *tmp;
	int current_ants;

	current_ants = 1;
	ants = s->shortest;
	tmp = get_end_room(s);
	while (tmp->content_size != (size_t)s->number_of_ants)
	{
		if (current_ants <= s->number_of_ants)
		{
			func(ants, current_ants);
		}
		else
			func(ants, 0);
		current_ants++;
		printf("\n");
	}
}

// int find_best_way(t_s *s, t_list *find)
// {
// 	t_list *new;

// 	while (find != NULL)
// 	{
// 		if (find->content == s->li_end)
// 		{
// 			new = ft_lstnew(find->content, 0);
// 			new = (void*)s->li_end;
// 			ft_lstadd(&s->shortest, new);
// 			return (1);
// 		}
// 		else if	(find_best_way(s, ((t_li*)find->content)->connect) == 1)
// 		{
// 			new = ft_lstnew(find->content, 0);
// 			new = (void*)find->content;
// 			ft_lstadd(&s->shortest, new);
// 		}
// 		find = find->next;
// 	}
// 	t_li *check;

// 	check = shortest;
// 	while (check != NULL)
// 	{
// 		printf("\nname of check room>>>%s\ncheck of check%d\n", check->name, check->check);
// 		check = check->next;
// 	}
// }


// create a new list, which contain rooms, which have paths to end.
 // if some of rooms have not point on next room or have not point to end - this rooms i need to exclude from list
// then i need to move from start to end and write to new list every room, except that rooms, which i excluded in previous func.



// L1-2
// L1-3 L2-2
// L1-1 L2-3 L3-2
// L2-1 L3-3
// L3-1

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
	if (check_count_hyphen(s, buff) == 1)
	{
		s->m_connect = ft_strsplit(buff, '-');
		if (s->m_connect[0] != NULL && s->m_connect[1] != NULL)
		{
			check_equal_elem(s);
			return (1);
		}
	}
	return (0);
}