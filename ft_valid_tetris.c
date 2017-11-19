/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:44:07 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/19 16:35:23 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	ft_d(int x, int y, int z, int t)
{
	if (x == z && t == y + 1)
		return (TRUE);
	return (FALSE);
}

static int	ft_r(int x, int y, int z, int t)
{
	if (x + 1 == z && t == y)
		return (TRUE);
	return (FALSE);
}

static void	ft_create_tab(int tab[4], t_tetri *tetri, char c)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		if (c == 'x')
			tab[i] = tetri->points[i].x;
		else
			tab[i] = tetri->points[i].y;
		++i;
	}
}

t_bool		ft_valid_tetri(t_tetri *tetris)
{
	int		s;
	int		ytab[4];
	int		xtab[4];

	s = 0;
	ft_create_tab(xtab, tetris, 'x');
	ft_create_tab(ytab, tetris, 'y');
	s = ft_d(xtab[0], ytab[0], xtab[1], ytab[1]) +
		ft_d(xtab[0], ytab[0], xtab[2], ytab[2]) +
		ft_d(xtab[0], ytab[0], xtab[3], ytab[3]) +
		ft_d(xtab[1], ytab[1], xtab[2], ytab[2]) +
		ft_d(xtab[1], ytab[1], xtab[3], ytab[3]) +
		ft_d(xtab[2], ytab[2], xtab[3], ytab[3]) +
		ft_r(xtab[0], ytab[0], xtab[1], ytab[1]) +
		ft_r(xtab[0], ytab[0], xtab[2], ytab[2]) +
		ft_r(xtab[0], ytab[0], xtab[3], ytab[3]) +
		ft_r(xtab[1], ytab[1], xtab[2], ytab[2]) +
		ft_r(xtab[1], ytab[1], xtab[3], ytab[3]) +
		ft_r(xtab[2], ytab[2], xtab[3], ytab[3]);
	if (s >= 3)
		return (TRUE);
	else
		return (FALSE);
}

t_bool		ft_valid_tetris(t_list *lst)
{
	while (lst)
	{
		if (ft_valid_tetri(lst->content) == FALSE)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}
