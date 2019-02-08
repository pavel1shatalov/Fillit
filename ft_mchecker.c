/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:46:45 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/08 21:38:59 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_grandchecker(char t[6][6])
{
	int		i;
	int		j;
	int		c;
	int		n;

	c = 0;
	i = 1;
	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 6; b++) {
			printf("%c	", t[a][b]);
		}
		printf("\n");
	}
	while (t[i][1])
	{
		j = 1;
		while (t[i][j])
		{
			if (t[i][j] != '.' && t[i][j] != '#')
				return (1);
			if (t[i][j] == '#')
				c++;
			j++;
		}
		i++;
	}
	printf("%d\n", c);
	if (c != 4)
		return (1);
	n = 0;
	i = 1;
	while (t[i][1])
	{
		j = 1;
		while (t[i][j])
		{
			if (t[i][j] == '#')
			{
				if (t[i - 1][j] == '#')
					n++;
				if (t[i + 1][j] == '#')
					n++;
				if (t[i][j - 1] == '#')
					n++;
				if (t[i][j + 1] == '#')
					n++;
			}
			j++;
		}
		i++;
	}
	printf("%d\n", n);
	if (n != 6 && n != 8)
		return (1);
	return (0);
}

int		ft_mchecker(char *file)
{
	int		fd;
	int		i;
	int		k;		
	char	*line;
	char	t[6][6];

	fd = open(file, O_RDONLY);
	i = 6;
	while (i--)
	{
		t[0][i] = '\0';
		t[5][i] = '\0';
	}
	i = 1;
	while (get_next_line(fd, &line))
	{
		ft_putstr("lol\n");
		if (i < 5)
		{
			t[i][0] = '\0';
			k = 0;
			while (line[k++])
				t[i][k] = line[k - 1];
			ft_strdel(&line);
			i++;
			if (i != 5)
				continue ;
		}
		get_next_line(fd, &line);
		ft_putstr("kek\n");
		ft_strdel(&line);
		if (!ft_grandchecker(t))
			i = 1;
		else
			return (1);
	}
	close(fd);
	return (0);
}
