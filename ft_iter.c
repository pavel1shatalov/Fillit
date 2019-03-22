/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:53:15 by ggerhold          #+#    #+#             */
/*   Updated: 2019/03/17 21:26:09 by ggerhold         ###   ########.fr       */
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

void	ft_iter(int *code, char *map, int n)
{
	int		nb;
	int		cut;

	while (42)
	{
		while (*code && ft_fill(code, map, n))
			code += 3;
		if (!*code)
		{
			ft_putstr(map);
			return ;
		}
		nb = ft_nblock(code, n);
		cut = ft_search(map, nb);
		ft_delete(map, nb);
		while (!ft_fill(code - 3, map + cut + 1, n))
		{
			nb--;
			code -= 3;
			if (nb)
			{
				cut = ft_search(map, nb);
				ft_delete(map, nb);
			}
			else
			{
				map = ft_mupdate(code, map);
				break ;
			}
		}
	}
}
