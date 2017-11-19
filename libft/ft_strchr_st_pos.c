/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_st_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:12:39 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/19 21:15:24 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_st_pos(const char *s, size_t start, int c)
{
	int		pos;

	if (!s || start >= ft_strlen(s))
		return (-1);
	pos = start;
	while (s[pos] && s[pos] != c)
		++pos;
	return ((s[pos] == '\0' && c != '\0') ? -1 : pos);
}
