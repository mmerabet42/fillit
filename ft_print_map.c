/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:41:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/22 23:08:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	ft_new_tetri(char c, int x, int y, int p0x, int p0y,
		int p1x, int p1y, int p2x, int p2y, int p3x, int p3y)
{
	t_tetri	p;

	p.ignore = TRUE;
	p.c = c;
	p.pos.x = x;
	p.pos.y = y;
	p.points[0].x = p0x;
	p.points[0].y = p0y;
	p.points[1].x = p1x;
	p.points[1].y = p1y;
	p.points[2].x = p2x;
	p.points[2].y = p2y;
	p.points[3].x = p3x;
	p.points[3].y = p3y;
	return (p);
}

void		ft_map_tetris(t_mapdata *mapdata)
{
	int	i;
	int	xpos, ypos;
	t_tetri	*tmp;
	t_list	*it;

	i = mapdata->size;
	if (!(mapdata->arr = (char *)malloc(sizeof(char) * (mapdata->size * mapdata->size))))
		return ;
	it = mapdata->tetris;
	while (it)
	{
		i = 0;
		tmp = (t_tetri *)it->content;
		while (!tmp->ignore && i < 4)
		{
			ypos = tmp->pos.y + tmp->points[i].y;
			xpos = tmp->pos.x + tmp->points[i].x;
			if (xpos < mapdata->size && ypos < mapdata->size)
				mapdata->arr[xpos * mapdata->size + ypos] = tmp->c;
			++i;
		}
		it = it->next;
	}
}

void	ft_print_map(t_mapdata *mapdata)
{
	int	xpos;
	int	ypos;

	ypos = 0;
	while (ypos < mapdata->size)
	{
		xpos = 0;
		while (xpos < mapdata->size)
		{
			ft_putchar(mapdata->arr[xpos * mapdata->size + ypos]);
			++xpos;
		}
		ft_putchar('\n');
		++ypos;
	}
}
