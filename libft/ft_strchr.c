/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:54:37 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/14 15:27:44 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*str;

	a = (char)c;
	str = (char *)s;
	if (a == '\0')
		return (str + ft_strlen(s));
	while (*str)
	{
		if (*str == a)
			return (str);
		str++;
	}
	return (NULL);
}
