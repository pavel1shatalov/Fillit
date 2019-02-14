/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbtetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:16:30 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 17:25:11 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nbtetr(char *file)
{
	int		fd;
	int		cnt;
	char	*line;

	cnt = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
		cnt++;
	return (cnt / 5 + 1);
	close (fd);
}
