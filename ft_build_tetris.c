/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:43:43 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/21 19:00:00 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_tab_coord(char b, int i, int y, int tab[3])
{
	tab[0] = b;
	tab[1] = i - 5 * (y);
	tab[2] = y;
	return (tab);
}

static void		ft_advance_y(char c, int *y)
{
	if (c == '\n')
		(*y)++;
}

static t_tetri	*ft_pos_tetri(int tab[3], int j, t_tetri *tetri)
{
	tetri->c = (char)tab[0];
	tetri->pos.x = 0;
	tetri->pos.y = 0;
	tetri->ignore = TRUE;
	tetri->points[j].x = tab[1];
	tetri->points[j].y = tab[2];
	return (tetri);
}

static t_tetri	*ft_build_tetri(char *str, char b, t_tetri *tetri)
{
	int		i;
	int		j;
	int		y;
	int		tab[3];

	y = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		ft_advance_y(str[i], &y);
		if (str[i] == '#')
		{
			if (j > 3)
				return (NULL);
			if (j == 0)
				tetri = (t_tetri *)malloc(sizeof(t_tetri));
			if (!tetri)
				return (NULL);
			ft_pos_tetri(ft_tab_coord(b, i, y, tab), j, tetri);
			++j;
		}
		i++;
	}
	return ((j != 4) ? NULL : tetri);
}

t_bool			ft_build_tetris(t_list *lst)
{
	char	c;
	t_tetri	*t;

	c = 'A';
	while (lst)
	{
		t = ft_build_tetri(lst->content, c++, t);
		if (!t)
			return (FALSE);
		lst->content = (void *)t;
		lst = lst->next;
	}
	return (TRUE);
}
