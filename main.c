/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:40:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/16 18:58:49 by vtennero         ###   ########.fr       */
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
		ft_get_tetris(fd);
	else
		ft_putendl("error");
	return (0);
}
