/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:08:46 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/15 13:12:47 by ggerhold         ###   ########.fr       */
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
		ft_putstr("delete: ");
		ft_putchar('A' + (nb - 1));
		ft_putchar('\n');
		ft_putstr(map);
		ft_delete(map, nb);
		ft_putstr("deleted: ");
		ft_putchar('A' + (nb - 1));
		ft_putchar('\n');
		ft_putstr("I want to find place starting from the ");
		ft_putstr(ft_itoa(cut));
		ft_putstr(" + 1 cell (first cell in a row is 0, 7, ..., 35)\n");
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
