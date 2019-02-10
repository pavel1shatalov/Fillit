/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:45:06 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/10 22:06:40 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_filler(int *code)
{
	char	*map;
	int		i;
	int		j;

	map = ft_map(4);
	i = 0;
	j = 0;
	while (code[j] && \
			map[i] && \
			map[i + *(code + j)] && \
			map[i + *(code + (j + 1))] && \
			map[i + *(code + (j + 2))])
	{
		if (map[i] == '.' \
				&& map[i + *(code + j)] == '.' \
				&& map[i + *(code + j) + *(code + j + 1)] == '.' \
				&& map[i + *(code + j) + *(code + j + 1) + *(code + j + 2)] == '.') 
		{
			printf("\n%d\n", i);
			printf("\n%c\n", map[i]);
			map[i] = 'A' + (j / 3);

			printf("%c\n", map[i]);

			printf("\n%s\n", map);

			printf("%d", *(code + j)); 
			map[i + *(code + j)] = 'A' + (j / 3);
			
			printf("%d", *(code + j + 1)); 
			map[i + *(code + j) + *(code + j + 1)] = 'A' + (j / 3);
			
			printf("%d", *(code + j + 2)); 
			map[i + *(code + j) + *(code + j + 1) + *(code + j + 2)] = 'A' + (j / 3);
			j += 3;
		}
		i++;
	}
	return (map);
}

