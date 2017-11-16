/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:41:21 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/16 17:16:25 by mmerabet         ###   ########.fr       */
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

typedef int t_bool;

void	ft_fillit(int fd);

t_list	*ft_get_tetris(int fd);
char	**ft_resolve_tetris(t_list *tetris, int *size);
void	ft_print_tetris(char **arr, int size);

#endif
