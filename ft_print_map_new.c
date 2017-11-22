/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:41:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/22 22:27:21 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_map_tetris(t_mapdata *map)
{
	int		i;
	t_point	pos;
	t_tetri	*t;
	t_list	*it;

	if (!(map->arr = (char *)malloc((map->size * map->size))))
		return ;
	ft_memset(map->arr, '.', map->size * map->size);
	it = map->tetris;
	while (it)
	{
		t = (t_tetri *)it->content;
		i = -1;
		while (!t->ignore && ++i < 4)
		{
			pos.x = t->pos.x + t->points[i].x;
			pos.y = t->pos.y + t->points[i].y;
			if (pos.x < map->size && pos.y < map->size)
				map->arr[pos.x * map->size + pos.y] = t->c;
		}
		it = it->next;
	}
}

void	ft_print_map(t_mapdata *map)
{
	int	i;

	i = 0;
	while (i < map->size * map->size)
	{
		if (i && i % map->size == 0)
			ft_putchar('\n');
		ft_putchar(map->arr[i]);
		++i;
	}
	return ;
	t_point	pos;

	pos.y = 0;
	while (pos.y < map->size)
	{
		pos.x = 0;
		while (pos.x < map->size)
		{
			ft_putchar(map->arr[pos.x * map->size + pos.y]);
			++pos.x;
		}
		ft_putchar('\n');
		++pos.y;
	}
}
