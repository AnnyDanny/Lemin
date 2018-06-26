/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:45:52 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/24 17:45:52 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *buff;
	t_list *tmp;

	if (alst != NULL && *alst != NULL && del != NULL)
	{
		tmp = *alst;
		while (tmp != NULL)
		{
			buff = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = buff;
		}
		*alst = NULL;
	}
}
