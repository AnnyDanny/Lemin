/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_lemin_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:39:15 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:39:16 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

void			error_exit(char const *str)
{
	ft_printf("\nERROR >>> %s\n", str);
	exit(0);
}

void			ft_li_add(t_li **alst, t_li *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_li			*li_new(char *number_of_room, int coord_x, int coord_y)
{
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

int				check_start_end(char *buff)
{
	if (ft_strequ(buff, "##start") == 1)
		return (1);
	if (ft_strequ(buff, "##end") == 1)
		return (2);
	return (0);
}
