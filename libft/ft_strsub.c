/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:25:13 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/07 15:15:16 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		ind;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	ind = 0;
	while (len--)
	{
		str[ind] = s[ind + start];
		ind++;
	}
	str[ind] = '\0';
	return (str);
}
