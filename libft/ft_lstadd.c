/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:00:48 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/19 16:59:30 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *elem)
{
	if (alst && elem)
	{
		if (*alst)
			(*alst)->parent = elem;
		elem->next = *alst;
		elem->parent = NULL;
		*alst = elem;
	}
}
