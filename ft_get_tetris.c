/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:11:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 11:15:30 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*ft_get_tetris(int fd)
{
	t_list	*lst;
	char	buf[6];
	int		buffsize;
	int		i;

	i = 0;
	buffsize = 5;
	lst = ft_read_tetris(fd, buf, buffsize, i);
	if (!lst)
		return (NULL);
	if (ft_build_tetris(lst) == FALSE)
		return (NULL);
	if (ft_valid_tetris(lst) == FALSE)
		return (NULL);
	lst = ft_absolute_tetris(lst);
	return (lst);
}
