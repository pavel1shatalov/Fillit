/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:08:46 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 18:07:22 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_search(char *map, int nb)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'A' + (nb - 1))
			break ;
		i++;
	}
	return (i);
}

void	ft_delete(char *map, int nb)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'A' + (nb - 1))
			map[i] = '.';
		i++;
	}
}

int		ft_backtrack(int *code, char *map, int n)
{
	int		nb;
	int		cut;

	nb = ft_nblock(code, n);
	if (nb)
	{
		cut = ft_search(map, nb);
		ft_delete(map, nb);
		if (ft_fill(code - 3, map + cut + 1, n))
			if (ft_recur(code, map, n))
				return (1);
		if (ft_backtrack(code - 3, map, n))
				return (1);
	}
	if (ft_recur(code, ft_mupdate(code, map), n))
			return (1);
	return (0);
}
