/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_tetris.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:29:05 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/20 19:34:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_comp_coord(int tab[4])
{
	int		min;
	int		i;

	i = 0;
	min = 4;
	while (i++ < 4)
		if (tab[i] < min)
			min = tab[i];
	return (min);
}
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
static t_tetri	*ft_absolute_tetri(t_tetri *tetri)
{
	int		xtab[4];
	int		ytab[4];
	int		i;
	int		xmin;
	int		ymin;

	i = 0;

	while (i++ < 4)
	{
		xtab[i] = tetri->points[i].x;
		ytab[i] = tetri->points[i].y;
	}
	xmin = ft_comp_coord(xtab);
	ymin = ft_comp_coord(ytab);
	return (ft_change_coord(tetri, xmin, ymin));
}

t_list			*ft_absolute_tetris(t_list *lst)
{
	t_tetri	*t;

	while (lst)
	{
		t = ft_absolute_tetri(lst->content);
		lst->content = (void *)t;
		lst = lst->next;
	}
	return (lst);
}
