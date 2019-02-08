/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:08:23 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/15 18:49:20 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*rev;

	if (!s)
		return (NULL);
	while (WHITESPACE(*s))
		s++;
	if (!s)
		return (NULL);
	rev = s + ft_strlen(s) - 1;
	while (WHITESPACE(*rev))
		rev--;
	return (ft_strsub(s, 0, ft_strlen(s) - ft_strlen(rev) + 1));
}
