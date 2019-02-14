/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:53:01 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 23:38:25 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill(int *code, char *map, int n)
{
	int		nb;
	int		i;

	ft_putstr("\ncounting the block\n");
	nb = ft_nblock(code, n);
	i = 0;
	ft_putstr("add: ");
	ft_putchar('A' + nb);
	ft_putchar('\n');
	while (map[i])
	{
		if (map[i] == '.' \
				&& map[i + *(code)] == '.' \
				&& map[i + *(code) + *(code + 1)] == '.' \
				&& map[i + *(code) + *(code + 1) + *(code + 2)] == '.')
		{
			map[i] = 'A' + nb;
			map[i + *(code)] = 'A' + nb;
			map[i + *(code) + *(code + 1)] = 'A' + nb;
			map[i + *(code) + *(code + 1) + *(code + 2)] = 'A' + nb;
			ft_putstr(map);
			return (1);
		}
		i++;
	}
	ft_putstr("fail\n");
	return (0);
}

