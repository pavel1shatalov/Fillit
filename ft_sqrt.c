/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:44:53 by thansen           #+#    #+#             */
/*   Updated: 2019/02/14 15:52:20 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int		root;

	root = n;
	while (n != root * root && root != 0)
		root--;
	if (!root)
		return (ft_sqrt(n + 1));
	else
	{
		printf("%d", root);
		return (root);
	}
}
