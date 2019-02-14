/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:19:26 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 13:46:13 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_backtrack(int *code, char *map, int n)
{
	int		nb;
	int		i;
	int		j;

	nb = ft_nblock(code, n);
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
		if (ft_fill(code - 3, map + j + 1, n))
		{
			if (ft_recur(code, map, n))
				return (1);
		}
		else
		{
			printf("DOUBLE KILL\n%s\n", map);
			if (ft_backtrack(code - 3, map, n))
				return (1);
		}
	}
	else
	{
		printf("UPDATE\n");
		ft_cupdate(code);
		if (ft_recur(code, ft_mupdate(map), n))
			return (1);
	}
	return (0);
}
