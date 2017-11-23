/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:40:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 11:12:26 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;

	if (argc != 2)
		ft_putendl("usage: ./fillit sample_file");
	else if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		if ((lst = ft_get_tetris(fd)) == NULL)
			ft_putendl("error");
		else
			ft_solve_tetris(lst);
	}
	else
		ft_putendl("error");
	return (0);
}
