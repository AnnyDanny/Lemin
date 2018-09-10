/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_lemin_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:38:04 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:38:05 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

int				check_two_hashes(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#' && buff[i + 1] == '#')
			return (1);
		i++;
	}
	return (0);
}

int				check_comment(char *buff)
{
	if (buff[0] == '#')
		return (1);
	return (0);
}

int				check_no_two_hashes(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (check_two_hashes(buff) == 1)
			return (1);
		i++;
	}
	return (0);
}

int				check_digits_in_str(char *buff)
{
	int i;

	i = 0;
	if (buff == NULL)
		return (0);
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int				check_right(t_s *s, char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if ((check_digits_in_str(buff) == 1 && check_comment(buff) == 0)
			|| check_plus(buff) == 1 || check_plus(buff) == 0)
		{
			s->number_of_ants = ft_atoi(buff);
			ft_strdel(&buff);
			if (s->number_of_ants <= 0)
				return (0);
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}
