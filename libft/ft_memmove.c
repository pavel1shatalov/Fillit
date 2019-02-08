/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:21:13 by ggerhold          #+#    #+#             */
/*   Updated: 2018/12/24 17:22:19 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dp;
	const char	*sp;

	dp = (char*)dst;
	sp = (const char*)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	if (dst > src)
		while (len--)
			dp[len] = sp[len];
	return (dst);
}
