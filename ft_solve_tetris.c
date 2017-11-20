/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tetris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:33:18 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/20 22:14:31 by mmerabet         ###   ########.fr       */
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

t_bool		ft_check_collisions(t_tetri *a, t_mapdata *mapdata)
{
	int			i;
	int			j;
	t_tetri		*tmp;
	t_list		*lst;

	lst = mapdata->tetris;
	if (lst == NULL)
	{
		i = 0;
		while (i < 4)
		{
			if (a->pos.x + a->points[i].x >= mapdata->size
				|| a->pos.y + a->points[i].y >= mapdata->size)
			{
				//printf("POINT OF %c IS OUTSIDE MAP\n", a->c);
				return (TRUE);
			}
			++i;
		}
		return (FALSE);
	}
	while (lst)
	{
		tmp = (t_tetri *)lst->content;
		if (a != tmp)
		{
			//printf("CHECKING COLLISION %c AND %c\n", a->c, tmp->c);
			i = 0;
			while (i < 4)
			{
				j = 0;
				while (j < 4)
				{
					if (ft_pointequ(a->pos, a->points[i], tmp->pos, tmp->points[j]))
					{
						//printf("COLLISION BETWEEN %c AND %c\n", a->c, tmp->c);
						return (TRUE);
					}
					else if (a->pos.x + a->points[i].x >= mapdata->size
						|| a->pos.y + a->points[i].y >= mapdata->size)
					{
						//printf("POINT OF %c IS OUTSIDE MAP\n", a->c);
						return (TRUE);
					}
					++j;
				}
				++i;
			}
		}
		lst = lst->next;
	}
	//printf("%c NOT COLLIDING\n", a->c);
	return (FALSE);
}

int			ft_inner_fillit(t_list *curr, t_mapdata *mapdata)
{
	t_tetri	*current_tetri;

	if (curr)
	{
		current_tetri = (t_tetri *)curr->content;
		//printf("PLACING %c %d %d\n", current_tetri->c, current_tetri->pos.x, current_tetri->pos.y);
		if (ft_check_collisions(current_tetri, mapdata))
		{
			if (++current_tetri->pos.x >= mapdata->size)
			{
				current_tetri->pos.x = 0;
				if (++current_tetri->pos.y >= mapdata->size)
				{
					current_tetri->pos.y = 0;
					//printf("%c CANT BE PLACED REPLACING PREVIOUS TETRI\n", current_tetri->c);
					if (!mapdata->tetris)
						++mapdata->size;
					else
						return (0);
				}
			}
			return (ft_inner_fillit(curr, mapdata));
		}
		else
		{
			//printf("ADDING %c TO TETRIS\n", current_tetri->c);
			if (mapdata->tetris)
				ft_lstpush(mapdata->tetris, ft_lstnew(curr->content, curr->content_size));
			else
				mapdata->tetris = ft_lstpush(mapdata->tetris, ft_lstnew(curr->content, curr->content_size));
			//printf("PLACING NEXT TETRI\n");
			//ft_map_tetris(mapdata);
			//ft_print_map(mapdata);
			//printf("\n\n");
			if (ft_inner_fillit(curr->next, mapdata) == 0)
			{
				//printf("REPLACING %c\n", current_tetri->c);
				ft_lsterase(&mapdata->tetris, current_tetri, sizeof(t_tetri));
				if (++current_tetri->pos.x >= mapdata->size)
				{
					//printf("X IS TOO BIG %c %d %d\n", current_tetri->c, current_tetri->pos.x, current_tetri->pos.y);
					current_tetri->pos.x = 0;
					if (++current_tetri->pos.y >= mapdata->size)
					{
					//	printf("MAP IS TOO SMALL FOR %c\n", current_tetri->c);
						current_tetri->pos.y = 0;
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
		while (i < 4)
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
	mapdata->tetris = NULL;
	ft_inner_fillit(tetris, mapdata);
	ft_map_tetris(mapdata);
	return (mapdata);
}
