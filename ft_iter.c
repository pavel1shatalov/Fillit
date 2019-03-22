/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:53:15 by ggerhold          #+#    #+#             */
/*   Updated: 2019/03/22 20:03:15 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_search(char *map, int nb)
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

void		ft_delete(char *map, int nb)
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

t_update	ft_backtrack(int *pseudocode, char *pseudomap, int n)
{
	int			nb;
	int			cut;
	t_update	pseudo;

	nb = ft_nblock(pseudocode, n);
	cut = ft_search(pseudomap, nb);
	ft_delete(pseudomap, nb);
	while (!ft_fill(pseudocode - 3, pseudomap + cut + 1, n))
	{
		nb--;
		pseudocode -= 3;
		if (nb)
		{
			cut = ft_search(pseudomap, nb);
			ft_delete(pseudomap, nb);
		}
		else
		{
			pseudomap = ft_mupdate(pseudocode, pseudomap);
			break ;
		}
	}
	pseudo.code = pseudocode;
	pseudo.map = pseudomap;
	return (pseudo);
}

void		ft_iter(int *code, char *map, int n)
{
	void		*tmp;
	t_update	set;

	tmp = (void *)code;
	while (42)
	{
		while (*code && ft_fill(code, map, n))
			code += 3;
		if (!*code)
		{
			ft_putstr(map);
			ft_strdel(&map);
			ft_memdel(&tmp);
			return ;
		}
		set = ft_backtrack(code, map, n);
		code = set.code;
		map = set.map;
	}
}
