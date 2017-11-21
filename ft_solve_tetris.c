/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tetris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:33:18 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/21 19:10:46 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_bool		ft_pointequ(t_point apos, t_point a, t_point bpos, t_point b)
{
	if (apos.x + a.x == bpos.x + b.x && apos.y + a.y == bpos.y + b.y)
		return (TRUE);
	return (FALSE);
}

t_bool		ft_tetriout(t_tetri *a, int size)
{
	int	i;

	i = -1;
	while (++i < 4)
		if ((a->pos.x + a->points[i].x) >= size
			|| (a->pos.y + a->points[i].y) >= size)
			return (TRUE);
	return (FALSE);
}

t_bool		ft_check_collisions(t_tetri *a, t_list *tetris)
{
	int			i;
	int			j;
	t_tetri		*tmp;

	if (!tetris)
		return (FALSE);
	while (tetris)
	{
		tmp = (t_tetri *)tetris->content;
		if (a != tmp && tmp->ignore == FALSE)
		{
			//printf("CHECKING COLLISION %c AND %c\n", a->c, tmp->c);
			i = -1;
			while (++i < 4)
			{
				j = -1;
				while (++j < 4)
					if (ft_pointequ(a->pos, a->points[i], tmp->pos, tmp->points[j]))
						//printf("COLLISION BETWEEN %c AND %c\n", a->c, tmp->c);
						return (TRUE);
			}
		}
		tetris = tetris->next;
	}
	//printf("%c NOT COLLIDING\n", a->c);
	return (FALSE);
}

int			ft_inner_fillit(t_list *curr, t_mapdata *mapdata)
{
	t_tetri	*t;

	if (curr)
	{
		t = (t_tetri *)curr->content;
		//printf("PLACING %c %d %d\n", current_tetri->c, current_tetri->pos.x, current_tetri->pos.y);
		if (ft_tetriout(t, mapdata->size) || ft_check_collisions(t, mapdata->tetris))
		{
			if (++t->pos.x >= mapdata->size)
			{
				t->pos.x = 0;
				if (++t->pos.y >= mapdata->size)
				{
					t->pos.y = 0;
					//printf("%c CANT BE PLACED REPLACING PREVIOUS TETRI\n", current_tetri->c);
					if (curr == mapdata->tetris)
						++mapdata->size;
					else
						return (0);
				}
			}
			return (ft_inner_fillit(curr, mapdata));
		}
		else
		{
			t->ignore = FALSE;
			//printf("ADDING %c TO TETRIS\n", current_tetri->c);
			//printf("PLACING NEXT TETRI\n");
			//ft_map_tetris(mapdata);
			//ft_print_map(mapdata);
			//printf("\n\n");
			//sleep(1);
			//system("clear");
			if (ft_inner_fillit(curr->next, mapdata) == 0)
			{
				//printf("REPLACING %c\n", current_tetri->c);
				t->ignore = TRUE;
				if (++t->pos.x >= mapdata->size)
				{
					//printf("X IS TOO BIG %c %d %d\n", current_tetri->c, current_tetri->pos.x, current_tetri->pos.y);
					t->pos.x = 0;
					if (++t->pos.y >= mapdata->size)
					{
					//	printf("MAP IS TOO SMALL FOR %c\n", current_tetri->c);
						t->pos.y = 0;
					}
				}
				return (ft_inner_fillit(curr, mapdata));
			}
		}
	}
	return (1);
}

void		ft_map_tetris(t_mapdata *mapdata)
{
	int	i;
	int	xpos, ypos;
	t_tetri	*tmp;
	t_list	*it;

	i = mapdata->size;
	if ((mapdata->arr = (char **)malloc(sizeof(char *) * i)) == NULL)
		return ;
	i = 0;
	while (i < mapdata->size)
	{
		mapdata->arr[i] = (char *)malloc(sizeof(char) * mapdata->size);
		ft_memset(mapdata->arr[i], '.', mapdata->size);
		++i;
	}
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
				mapdata->arr[ypos][xpos] = tmp->c;
			++i;
		}
		it = it->next;
	}
}

t_mapdata	*ft_solve_tetris(t_list *tetris)
{
	t_mapdata	*mapdata;
	int			nbtetris;

	if (!(mapdata = (t_mapdata *)malloc(sizeof(t_mapdata))))
		return (NULL);
	nbtetris = ft_lstsize(tetris);
	mapdata->size = 2;
	while (ft_pow(mapdata->size, 2) < nbtetris * 4)
		++mapdata->size;
	mapdata->tetris = tetris;
	ft_inner_fillit(tetris, mapdata);
	ft_map_tetris(mapdata);
	return (mapdata);
}
