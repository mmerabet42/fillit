/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:41:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 11:06:26 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_map_tetris(t_mapdata *map)
{
	int		i;
	t_point	pos;
	t_tetri	*tmp;
	t_list	*it;

	if (!(map->arr = (char *)malloc(sizeof(char) * (map->size * map->size))))
		return ;
	ft_memset(map->arr, '.', map->size * map->size);
	it = map->tetris;
	while (it)
	{
		i = -1;
		tmp = (t_tetri *)it->content;
		while (!tmp->ignore && ++i < 4)
		{
			pos.y = tmp->pos.y + tmp->points[i].y;
			pos.x = tmp->pos.x + tmp->points[i].x;
			if (pos.x < map->size && pos.y < map->size)
				map->arr[pos.x * map->size + pos.y] = tmp->c;
		}
		it = it->next;
	}
}

void	ft_print_map(t_mapdata *mapdata)
{
	t_point	pos;

	pos.y = -1;
	while (++pos.y < mapdata->size)
	{
		pos.x = -1;
		while (++pos.x < mapdata->size)
			ft_putchar(mapdata->arr[pos.x * mapdata->size + pos.y]);
		ft_putchar('\n');
	}
}
