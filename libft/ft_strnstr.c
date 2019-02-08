/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:30:19 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/14 15:42:12 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack[0] && !needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i < len)
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
				break ;
		}
		if (!needle[j])
			return ((char *)&haystack[i - j]);
		else
			i = i - j + 1;
	}
	return (NULL);
}
