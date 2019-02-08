/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:51:18 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/18 18:51:19 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cpnext;

	if (!alst || !*alst)
		return ;
	while ((*alst)->next)
	{
		cpnext = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = cpnext;
	}
	ft_lstdelone(alst, del);
}
