/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:42:22 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/16 19:48:16 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	long	num;
	int		cnt;

	sign = 0;
	num = (long)n;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	cnt = 1;
	while (n /= 10)
		cnt++;
	if (!(str = (char *)malloc(sizeof(char) * (sign + cnt + 1))))
		return (NULL);
	str[0] = '-';
	str[sign + cnt] = '\0';
	while (cnt--)
	{
		str[sign + cnt] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
