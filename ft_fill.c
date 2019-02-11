/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:53:01 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/11 22:21:58 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill(int *code, char *map, char *file)
{
	int		nb;
	int		i;

	nb = ft_nblock(code, file);
//	printf("%d\n", nb + 1);
	i = 0;
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
			return (1);
		}
		i++;
	}
//	if (nb == 4)
//		printf("%s\n", map);
	return (0);
}

