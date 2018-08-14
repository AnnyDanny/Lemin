/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 21:07:01 by gdanylov          #+#    #+#             */
/*   Updated: 2018/02/15 17:55:12 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list			*multifile_get_in_list(int fd, t_list **vika)
{
	t_list	*buf;
	t_list	*new;

	buf = *vika;
	while (buf && (size_t)fd != buf->content_size)
		buf = buf->next;
	if (buf && buf->content_size == (size_t)fd)
		return (buf);
	new = ft_lstnew("", 1);
	new->content_size = fd;
	ft_lstadd(vika, new);
	return (*vika);
}

int				get_in_list(char *tmp, t_list *list, char **line)
{
	int			i;
	char		*tmp2;
	char		*g;

	i = 0;
	g = tmp;
	*line = ft_strsub(tmp, 0, ft_countstrclen(tmp, '\n'));
	if ((tmp = ft_strchr(tmp, '\n')) != NULL)
	{
		tmp++;
		tmp2 = list->content;
		list->content = ft_strdup(tmp);
		ft_strdel(&tmp2);
	}
	else
		ft_bzero(list->content, ft_strlen(list->content));
	ft_strdel(&g);
	return (1);
}

void			read_func(t_get *s, int fd)
{
	while (((*s).ret = read(fd, (*s).buf, BUFF_SIZE)) > 0)
	{
		(*s).t = (*s).tmp;
		(*s).tmp = ft_strjoin((*s).tmp, (*s).buf);
		ft_strdel(&(*s).t);
		ft_strclr((*s).buf);
		if (ft_strchr((*s).tmp, '\n'))
			break ;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*vika;
	t_get			s;

	s.buf = ft_strnew(BUFF_SIZE);
	s.tmp = ft_strnew(BUFF_SIZE);
	s.buf2 = multifile_get_in_list(fd, &vika);
	read_func(&s, fd);
	if (s.ret == -1 || fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	ft_strdel(&s.buf);
	s.d = s.tmp;
	s.tmp = ft_strjoin(s.buf2->content, s.tmp);
	ft_strdel(&s.d);
	if (ft_strlen(s.tmp) == 0 && s.ret == 0
	&& (vika == NULL || ft_strlen(s.buf2->content) == 0))
	{
		ft_strdel(&s.tmp);
		return (0);
	}
	get_in_list(s.tmp, s.buf2, line);
	return (1);
}
