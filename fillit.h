/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:41:21 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/19 13:12:12 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define TRUE 1
# define FALSE 0

#include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	char		c;
	t_point		pos;
	t_point		points[4];
}				t_tetri;

typedef struct	s_mapdata
{
	int			size;
	char		**arr;
	t_list		*tetris;
}				t_mapdata;

typedef int t_bool;

void	ft_fillit(int fd);

t_list		*ft_get_tetris(int fd);
t_mapdata	*ft_solve_tetris(t_list *tetris);
void		ft_map_tetris(t_mapdata *mapdata);
void		ft_print_map(t_mapdata *mapdata);
t_tetri		ft_new_tetri(char c, int x, int y, int p0x, int p0y,
					int p1x, int p1y, int p2x, int p2y, int p3x, int p3y);

#endif