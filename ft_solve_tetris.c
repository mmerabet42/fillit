/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tetris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:33:18 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/17 23:25:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

t_bool		ft_pointequ(t_point a, t_point b)
{
	if (a.x == b.x && a.y == b.y)
		return (TRUE);
	return (FALSE);
}

t_bool		ft_check_collision(t_tetris *a, t_tetris *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ft_pointequ(a->points[i], b->points[j]))
				return (TRUE);
			++j;
		}
		++i;
	}
	return (FALSE);
}

int			ft_recurfillit(t_list *curr, t_mapdata *mapdata)
{
	
}

t_mapdata	*ft_solve_tetris(t_list *tetris)
{
	t_mapdata	mapdata;
	int			nbtetris;
	int			i;
	int			xpos, ypos;

	nbtetris = ft_lstsize(tetris);
	mapdata.size = 2;

	while (ft_pow(mapdata.size, 2) < nbtetris * 4)
		++mapdata.size;
	ft_recurfillit(tetris, &mapdata);
	if ((mapdata.arr = (char **)malloc(sizeof(char *) * mapdata.size)) == NULL)
		return (NULL);
	i = 0;
	while (i < mapdata.size)
	{
		mapdata.arr[i] = (char *)malloc(sizeof(char) * mapdata.size);
		ft_memset(mapdata.arr[i], '.', mapdata.size);
		++i;
	}
	while (tetris)
	{
		i = 0;
		while (i < 4)
		{
			ypos = tetris->pos.y + tetris->points[i].y;
			xpos = tetris->pos.x + tetris->points[i].x;
			mapdata.arr[ypos][xpos] = tetris->c;
			++i;
		}
		tetris = tetris->next;
	}
	return (&mapdata);
}
