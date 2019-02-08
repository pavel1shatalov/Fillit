/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:52:35 by ggerhold          #+#    #+#             */
/*   Updated: 2019/01/18 18:52:36 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_lstcleaner(t_list *lst)
{
	t_list	*cp;

	while (lst)
	{
		free(lst->content);
		cp = lst->next;
		free(lst);
		lst = lst->next;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*temp;

	if (!lst && !f)
		return (NULL);
	if (!(result = f(lst)))
		return (NULL);
	temp = result;
	lst = lst->next;
	while (lst)
	{
		if (!(temp->next = f(lst)))
		{
			ft_lstcleaner(result);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
