/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:55:44 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 17:31:33 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *a, const char *b, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(a);
	j = 0;
	while (j < n && b[j])
		a[i++] = b[j++];
	a[i] = '\0';
	return (a);
}
