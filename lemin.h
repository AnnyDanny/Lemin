/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:12:41 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/25 14:12:42 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/get_next_line.h"
# include <fcntl.h>
# include "libft/includes/libft.h"


void	ft_bzero(void *s, size_t n);

int				get_next_line(const int fd, char **line);

typedef struct 		s_li
{
	char 			*name;
	int 			c_x;
	int 			c_y;
	t_list			*connect;
	int 			check;
	struct 	s_li 	*next;
}					t_li;	

typedef struct	s_s
{
	int number_of_ants;
	char *number_of_room_start;
	int comment;
	int two_hash;
	int s;
	int e;
	char *check_number;
	int i;
	int check;
	int spaces_start;
	int spaces_end;
	int spaces_other;
	int hyphen;
	int start_x;
	int start_y;
	char **m;
	char **m_connect;
	char *number_of_room_end;
	int end_x;
	int end_y;
	int other_x;
	int other_y;
	t_list *connect;
	t_list *con2;
	t_li *li;
	t_li *li_queue_head;
	t_li *li_queue_tail;
	t_li *li_start;
	t_li *li_end;
	t_li *li_other;
	t_li *head;
	t_list *shortest;
}				t_s;

void		cle_s(t_s *s);
void cle_m_dash(t_s *s);
void cle_m(t_s *s);
void get_start_coord(t_s *s, int fd, char *buff);
int check_digits_coord(t_s *s);
int check_valid_start_y(t_s *s);
int check_valid_start_x(t_s *s);
int check_valid_start_room(t_s *s);
int check_first_pos_room(char c);
int check_digits_in_str(char *buff);
int check_count_spaces_start(t_s *s, char *buff);
int check_count_spaces_end(t_s *s, char *buff);
void get_end_coord(t_s *s, int fd, char *buff);
t_li *li_new(char *number_of_room, int coord_x, int coord_y);
void	ft_li_add(t_li **alst, t_li *new);
int check_comment(char *buff);
int check_first_pos_room(char c);
void check_other_coords(t_s *s, char *buff);
int check_two_hashes(char *buff);
int check_connect(t_s *s, char *buff);
void error_exit(char const *str);
void create_queue(t_s *s);
// void find_best_way(t_s *s);
void from_end(t_s *s);
int check_start_end(char *buff);

#endif


// вход
// выход
// номер муравья
// номер комнаты
// координаты комнаты
