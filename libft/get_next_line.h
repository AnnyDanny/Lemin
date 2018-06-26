/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:12:41 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/25 14:12:42 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "includes/libft.h"

# define BUFF_SIZE 1

typedef struct	s_struct
{
	char		*t;
	char		*d;
	int			ret;
	char		*buf;
	char		*tmp;
	t_list		*buf2;
}				t_struct;

int				get_next_line(const int fd, char **line);

#endif
