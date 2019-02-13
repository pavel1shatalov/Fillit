/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:41:30 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/11 22:24:29 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_recur(int *code, char *map, char *file)
{
	if (!*code)
	{
		printf("\n%s\n", map);
		return (1);
	}
	if (ft_fill(code, map, file))
		if (ft_recur(code + 3, map, file))
			return (1);
	printf("KILL\n%s\n", map);
	if (ft_backtrack(code, map, file))
		return (1);
	return (0); //seems like never...
}
