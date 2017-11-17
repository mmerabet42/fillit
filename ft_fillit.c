/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:42:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/17 16:40:08 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*ft_get_tetriminos(int fd)
{
	
}

void	ft_fillit(int fd)
{
	t_tetris	*tetris;
	int			size;

	if ((tetris = ft_get_tetriminos(fd)) == NULL)
		return ;
	ft_print_tetris(ft_solve_tetris(tetris, &size), size);
}
