/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:19:26 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/11 22:22:17 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_backtrack(int *code, char *map, char *file)
{
	int		nb;
	int		i;
	int		j;

	nb = ft_nblock(code, file);
	if (nb)
	{
		i = 0;
		while (map[i])
		{
			if (map[i] == 'A' + (nb - 1))
			{
				j = i;
				break ;
			}
			i++;
		}
		while (map[i])
		{
			if (map[i] == 'A' + (nb - 1))
				map[i] = '.';
			i++;
		}
		//ft_recur(code - 3, map, file); //Has to be done from the next one
		if (ft_fill(code - 3, map + j + 1, file))
		{
			if (ft_recur(code, map, file))
				return (1);
		}
		else
		{
			printf("DOUBLE KILL\n%s\n", map);
			if (ft_backtrack(code - 3, map, file))
				return (1);
		}
	}
	else
	{
		printf("UPDATE\n");
		ft_cupdate(code);
		if (ft_recur(code, ft_mupdate(map), file))
			return (1);
	}
	return (0);
}
