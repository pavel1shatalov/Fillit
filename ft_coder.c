/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:39:33 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 16:51:58 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fillit.h"

int		*ft_coder(char *file)
{
	int		fd;
	char	*line;
	char 	*temp;
	char	*tetr;
	char	*full;
	int		*code;
	int		i;
	int		cnt;
	int		cut;

	fd = open(file, O_RDONLY);
	tetr = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		temp = tetr;
		full = ft_strjoin(line, "\n");
		tetr = ft_strjoin(temp, full);
		ft_strdel(&temp);
		ft_strdel(&full);
		ft_strdel(&line);
	}
	printf("%s", tetr);
	i = 0;
	cnt = 0;
	cut = 0;
	if (!(code = (int *)malloc(sizeof(int) * (3 * ft_nbtetr(file) + 1))))
		return (NULL);
	while (tetr[i])
	{
		if (cnt < 4 && tetr[i] == '#')
		{
			if (cnt == 0)
			{
				cut = i++;
				cnt++;
				continue ;
			}
			*code++ = i - cut;
			cut = i;
			cnt++;
			if (cnt == 4)
				cnt = 0;
		}
		i++;
	}
	*code = 0;
	return (code - 3 * ft_nbtetr(file));
}
