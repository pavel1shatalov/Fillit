/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:01:44 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 14:59:09 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fchecker(char *file)
{
	int		i;
	int		t;
	int		fd;
	char	*line;

	i = 1;
	t = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (i > 129)
			return (1);
		if (i % 5 == 0)
			t = 0;
		else
			t = 1;
		if ((t == 1 && ft_strlen(line) == 4) || \
				(t == 0 && !ft_strlen(line)))
		{
			i++;
			ft_strdel(&line);
			continue ;
		}
		else
		{
			ft_strdel(&line);
			return (1);
		}
	}
	close(fd);
	return (0);
}
