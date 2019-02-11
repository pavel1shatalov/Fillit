/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:41:30 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/11 18:14:39 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_recur(int *code, char *map)
{
	char *place;

	if (!*code)
	{
		printf("%s\n", map);
		return (1);
	}
	if (place = ft_find_place(code, map))
	{
		ft_fill(code, place);
		if (ft_recur(code + 3, map))
			return (1);
	}
	ft_del(code - 3, map);
	ft_recur(code - 3, map + 1); //map is changed!

	return (0);
}
