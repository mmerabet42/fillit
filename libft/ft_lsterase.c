/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsterase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:57:08 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/19 18:00:20 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lsterase(t_list *lst, const void *content, size_t content_size)
{
	t_list	*tmp;
	t_list	*lstdel;
	size_t	sztmp;

	if ((lstdel = ft_lstfind(lst, content, content_size)))
	{
		if ((tmp = lstdel->parent))
			tmp->next = lstdel->next;
		else if ((lstdel = lst->next))
		{
			if ((lst->next = lstdel->next))
				lstdel->next->parent = lst;
			ft_swapptr(lst->content, lstdel->content);
			sztmp = lst->content_size;
			lst->content_size = lstdel->content_size;
			lstdel->content_size = sztmp;
		}
		lstdel->parent = NULL;
		lstdel->next = NULL;
	}
	else
		return (NULL);
	return (lstdel);
}
