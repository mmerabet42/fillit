/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:55:24 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/21 12:55:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstpushback(t_list *lst,
								void *content,
								size_t content_size)
{
	return (ft_lstpush(lst, ft_lstcreate(content, content_size)));
}
