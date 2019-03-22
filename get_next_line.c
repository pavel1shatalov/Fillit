/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:25:58 by ggerhold          #+#    #+#             */
/*   Updated: 2019/03/22 17:13:46 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_convert(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_strsub(str, 0, i);
	tmp = ft_strsub(str, i + 1, ft_strlen(&str[i]));
	ft_strdel(&str);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tabl[4864];
	char		buff[BUFF_SIZE + 1];
	int			frag;
	char		*temp;

	if (fd < 0 || fd > 4864 || !line || read(fd, buff, 0) == -1)
		return (-1);
	if (tabl[fd] == NULL)
		tabl[fd] = ft_strnew(0);
	while (!ft_strchr(tabl[fd], '\n') && (frag = read(fd, buff, BUFF_SIZE)) > 0)
	{
		temp = tabl[fd];
		buff[frag] = '\0';
		tabl[fd] = ft_strjoin(temp, buff);
		ft_strdel(&temp);
	}
	if (*tabl[fd] != '\0')
	{
		tabl[fd] = ft_convert(tabl[fd], line);
		return (1);
	}
	ft_strdel(&tabl[fd]);
	return (0);
}
