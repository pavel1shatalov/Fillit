/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:43:30 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 14:43:27 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_mupdate(char *map)
{
	int		size;

	size = 0;
	while (map[size] != '\n')
		size++;
	ft_strdel(&map);
	return (ft_map(size + 1));
}
