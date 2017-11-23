/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tetris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:33:18 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 11:05:44 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_bool	ft_pointequ(t_point pos, t_point p, t_tetri *b)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (pos.x + p.x == b->pos.x + b->points[i].x
			&& pos.y + p.y == b->pos.y + b->points[i].y)
			return (TRUE);
	return (FALSE);
}

static t_bool	ft_check_collisions(t_tetri *a, t_list *tetris, int size)
{
	int			i;
	t_tetri		*tmp;

	i = -1;
	while (++i < 4)
		if ((a->pos.x + a->points[i].x >= size)
			|| (a->pos.y + a->points[i].y >= size))
			return (TRUE);
	if (tetris)
	{
		tmp = (t_tetri *)tetris->content;
		i = -1;
		if (a != tmp && tmp->ignore == FALSE)
			while (++i < 4)
				if (ft_pointequ(a->pos, a->points[i], tmp))
					return (TRUE);
	}
	else
		return (FALSE);
	return (ft_check_collisions(a, tetris->next, size));
}

static int		ft_increment_check(t_tetri *tetri, t_mapdata *map, int m)
{
	if (++tetri->pos.x >= map->size)
	{
		tetri->pos.x = 0;
		if (++tetri->pos.y >= map->size)
		{
			tetri->pos.y = 0;
			if (m == 0)
			{
				if (tetri == (t_tetri *)map->tetris->content)
					++map->size;
				else
					return (0);
			}
		}
	}
	return (1);
}

static int		ft_inner_fillit(t_list *curr, t_mapdata *map)
{
	t_tetri	*t;

	if (curr)
	{
		t = (t_tetri *)curr->content;
		if (ft_check_collisions(t, map->tetris, map->size))
		{
			if (ft_increment_check(t, map, 0) == 0)
				return (0);
			return (ft_inner_fillit(curr, map));
		}
		else
		{
			t->ignore = FALSE;
			if (ft_inner_fillit(curr->next, map) == 0)
			{
				t->ignore = TRUE;
				ft_increment_check(t, map, 1);
				return (ft_inner_fillit(curr, map));
			}
		}
	}
	return (1);
}

void			ft_solve_tetris(t_list *tetris)
{
	t_mapdata	*map;
	int			nbtetris;

	if (!(map = (t_mapdata *)malloc(sizeof(t_mapdata))))
		return ;
	nbtetris = ft_lstsize(tetris);
	map->size = 2;
	while (ft_pow(map->size, 2) < nbtetris * 4)
		++map->size;
	map->tetris = tetris;
	ft_inner_fillit(tetris, map);
	ft_map_tetris(map);
	ft_print_map(map);
}
