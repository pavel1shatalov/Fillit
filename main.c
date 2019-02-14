/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:40:47 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 23:42:18 by thansen          ###   ########.fr       */
/*   Updated: 2019/02/14 17:27:37 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		*code;
	char	*map;
	int		n;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("usage");
		//ft_usage();
		return (0);
	}
	close (fd);
	if (ft_fchecker(av[1]) || ft_mchecker(av[1]))
	{
		ft_putstr("error");
		return (0);
	}
	ft_putstr("ACHA");
	code = ft_coder(av[1]);
	n = ft_nbtetr(av[1]);
	map = ft_map(ft_sqrt(4 * n));
	map = ft_map(4);
	ft_recur(code, map, n);
	return (0);
}
