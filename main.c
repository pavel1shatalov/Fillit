/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:40:47 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/15 14:50:30 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		n;
	int		size;
	int		*code;
	char	*map;

	int		i;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	close (fd);
	if (ft_fchecker(av[1]) || ft_mchecker(av[1]))
	{
		ft_putstr("error");
		return (0);
	}
	ft_putstr("Validation is done!\n\n");
	n = ft_nbtetr(av[1]);
	size = ft_sqrt(4 * n);
	code = ft_code(av[1], n, size);
	
	i = 0;
	ft_putstr("Final code: ");
	while (code[i])
	{
		if (i % 3)
			ft_putchar(*ft_itoa(code[i]));
		else
		{
			ft_putchar('\n');
			ft_putchar(*ft_itoa(code[i]));
		}
		i++;
	}

	map = ft_map(size < 4 ? 4 : size);
	ft_putstr("\n\nThis is the map we're gonna fill:\n");
	ft_putstr(map);
	ft_recur(code, map, n);
	return (0);
}
