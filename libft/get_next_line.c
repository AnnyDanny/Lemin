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

#include "get_next_line.h"
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

void			read_func(t_struct *s, int fd)
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
	t_struct		s;

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


// char	*ft_realoc(char *save, int i, char *line)
// {
// 	char	*new;
// 	int		j;
// 	int		k;

// 	new = NULL;
// 	if (!save)
// 	{
// 		if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
// 			return (NULL);
// 	}
// 	else if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(save) + i + 1))))
// 		return (NULL);
// 	j = 0;
// 	if (save)
// 		while (save[j] != '\0')
// 		{
// 			new[j] = save[j];
// 			++j;
// 		}
// 	k = 0;
// 	while (k < i)
// 		new[j++] = line[k++];
// 	new[j] = '\0';
// 	ft_strdel(&save);
// 	return (new);
// }

// char	*ft_re_save(char *save, int i)
// {
// 	char *new;

// 	if (save[i] == '\0')
// 	{
// 		ft_strdel(&save);
// 		return (ft_strdup("\0"));
// 	}
// 	new = ft_strdup(&save[i + 1]);
// 	ft_strdel(&save);
// 	return (new);
// }

// void	ft_new_fd(t_list **l, int fd, t_list **new)
// {
// 	t_list *head;

// 	if (*l)
// 	{
// 		if (fd != (int)((*l)->content_size))
// 		{
// 			head = *l;
// 			while (head != NULL)
// 			{
// 				if ((int)(head->content_size) == fd && (*new = head))
// 					return ;
// 				head = head->next;
// 			}
// 			*new = ft_lstnew(NULL, 0);
// 			(*new)->content_size = fd;
// 			ft_lstadd(l, *new);
// 		}
// 		else
// 			*new = *l;
// 		return ;
// 	}
// 	*l = ft_lstnew(NULL, 0);
// 	(*l)->content_size = fd;
// 	*new = *l;
// }

// int		ft_gnl(t_list **s, int fd)
// {
// 	char	*buf;
// 	int		i;

// 	buf = NULL;
// 	if ((*s)->content == NULL || !ft_strchr((char*)((*s)->content), '\n'))
// 	{
// 		if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
// 			return (-1);
// 		while ((i = read(fd, buf, BUFF_SIZE)) > 0)
// 		{
// 			buf[i] = '\0';
// 			(*s)->content = (void*)ft_realoc((char*)((*s)->content), i, buf);
// 			if (ft_strchr(buf, '\n') != NULL)
// 				break ;
// 		}
// 		ft_strdel(&buf);
// 		if ((*s)->content && ((char*)((*s)->content))[0] == '\0' && i == 0)
// 			return (0);
// 	}
// 	return (1);
// }

// int		get_next_line(int fd, char **line)
// {
// 	t_list			*s;
// 	static t_list	*list = NULL;
// 	char			*buf;
// 	int				i;

// 	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
// 		return (-1);
// 	ft_new_fd(&list, fd, &s);
// 	i = ft_gnl(&s, fd);
// 	if (i <= 0)
// 		return (i);
// 	i = 0;
// 	while (((char*)(s->content))[i] != '\n' && ((char*)(s->content))[i] != 0)
// 		++i;
// 	buf = ft_strnew(i + 1);
// 	i = -1;
// 	while (((char*)(s->content))[++i] != '\n' && ((char*)(s->content))[i] != 0)
// 		buf[i] = ((char*)(s->content))[i];
// 	buf[i] = '\0';
// 	*line = buf;
// 	s->content = ft_re_save((char*)(s->content), i);
// 	return (1);
// }
