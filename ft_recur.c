/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:41:30 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/15 17:55:54 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_recur(int *code, char *map, int n)
{
	if (!*code)
	{
		ft_putstr(map);
		return (1);
	}
	if (ft_fill(code, map, n))
		if (ft_recur(code + 3, map, n))
			return (1);
	if (ft_backtrack(code, map, n))
		return (1);
	return (0);
}
