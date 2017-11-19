/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_st_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:17:06 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/19 21:18:43 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr_st_pos(const char *a, size_t start, const char *b)
{
	int		pos;
	size_t	j;

	if (!a || !b || start >= ft_strlen(a))
		return (-1);
	pos = start;
	while (a[pos])
	{
		j = 0;
		while (b[j] && a[pos + j] && (b[j] == a[pos + j]))
			++j;
		if (b[j] == '\0')
			return (pos);
		++pos;
	}
	return (-1);
}
