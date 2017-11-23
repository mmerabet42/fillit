/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_tetris.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:29:05 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/21 20:39:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_tetri	*ft_change_coord(t_tetri *tetri, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		tetri->points[i].x -= x;
		tetri->points[i].y -= y;
		++i;
	}
	return (tetri);
}

t_list			*ft_absolute_tetris(t_list *lst)
{
	int		xmin;
	int		ymin;
	int		i;
	t_tetri	*tetri;
	t_list	*it;

	it = lst;
	while (it)
	{
		tetri = (t_tetri *)it->content;
		i = -1;
		xmin = 4;
		ymin = 4;
		while (++i < 4)
		{
			if (tetri->points[i].x < xmin)
				xmin = tetri->points[i].x;
			if (tetri->points[i].y < ymin)
				ymin = tetri->points[i].y;
		}
		ft_change_coord(tetri, xmin, ymin);
		it = it->next;
	}
	return (lst);
}
