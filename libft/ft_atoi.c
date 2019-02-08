/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:48:09 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/14 18:47:01 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			sgn;
	int			ind;
	long long	tmp;
	long long	res;

	sgn = 1;
	ind = 0;
	res = 0;
	while (str[ind] == ' ' || (str[ind] >= 9 && str[ind] <= 13))
		ind++;
	if (str[ind] == '-')
		sgn = -1;
	if (str[ind] == '-' || str[ind] == '+')
		ind++;
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		tmp = res;
		res = res * 10 + (str[ind++] - '0');
		if (tmp > res)
			return (sgn < 0) ? 0 : -1;
	}
	return (sgn * (int)res);
}
