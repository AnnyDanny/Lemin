/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:46:58 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/24 17:46:59 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_delete(void *one, size_t i)
{
	i = 0;
	free(one);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *buff;
	t_list *vika;

	if (lst != NULL && f != NULL)
	{
		vika = (t_list *)malloc(sizeof(t_list));
		if (!vika)
			return (NULL);
		vika = f(lst);
		buff = vika;
		lst = lst->next;
		while (lst)
		{
			vika->next = f(lst);
			if (!vika->next)
			{
				ft_lstdel(&buff, &ft_delete);
				return (NULL);
			}
			vika = vika->next;
			lst = lst->next;
		}
		return (buff);
	}
	return (NULL);
}
