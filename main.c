/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:40:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/17 16:23:09 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_putendl("usage: ./fillit sample_file");
	else if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		if (ft_get_tetris(fd) == NULL)
			ft_putendl("KO");
		else
			ft_putendl("OK");
	}
	else
		ft_putendl("error");
	return (0);
}
