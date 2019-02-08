/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:11:41 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/14 13:38:03 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		len;
	char	*str;

	a = (char)c;
	len = ft_strlen(s);
	str = (char *)(s + len);
	while (len >= 0)
	{
		if (*str == a)
			return (str);
		len--;
		str--;
	}
	return (NULL);
}
