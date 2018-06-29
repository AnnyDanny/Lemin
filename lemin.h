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
	int start_x;
	int start_y;
	char **m;
	char *number_of_room_end;
	char *end_x;
	char *end_y;
	t_li *li;
	t_li *start;
}				t_s;

void		cle_s(t_s *s);
void cle_m(t_s *s);
int get_start_coord(t_s *s, int fd, char *buff);
int check_digits_coord(t_s *s);
int check_valid_start_y(t_s *s);
int check_valid_start_x(t_s *s);
int check_valid_start_room(t_s *s);
int check_first_pos_room(char c);
int check_digits_in_str(char *buff);
int check_count_spaces_start(t_s *s, char *buff);
int check_count_spaces_end(t_s *s, char *buff);
int get_end_coord(t_s *s, int fd, char *buff);
t_li *li_new(char *number_of_room, int coord_x, int coord_y);
void	ft_li_add(t_li **alst, t_li *new);
int check_comment(char *buff);

#endif


// вход
// выход
// номер муравья
// номер комнаты
// координаты комнаты
