/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:43:30 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/11 21:53:09 by ggerhold         ###   ########.fr       */
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