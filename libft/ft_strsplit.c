/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:58:49 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/16 17:41:42 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wrdcnt(char const *s, char c)
{
	int ind;
	int	cnt;

	ind = 0;
	cnt = 0;
	while (s[ind])
	{
		while (s[ind] == c)
			ind++;
		if (s[ind])
			cnt++;
		while (s[ind] && s[ind] != c)
			ind++;
	}
	return (cnt);
}

static char		*ft_strndup(char const *s1, size_t n)
{
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	s2[n] = '\0';
	while (n--)
		s2[n] = s1[n];
	return (s2);
}

static void		ft_memclr(char **arr, int n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		ind;
	int		cut;
	int		num;

	if (!s || !c)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1))))
		return (NULL);
	ind = 0;
	cut = 0;
	num = 0;
	while (s[ind])
	{
		while (s[ind] == c)
			ind++;
		cut = ind;
		while (s[ind] && s[ind] != c)
			ind++;
		if (ind > cut)
			if (!(arr[num++] = ft_strndup(s + cut, ind - cut)))
				ft_memclr(arr, num);
	}
	arr[num] = 0;
	return (arr);
}
