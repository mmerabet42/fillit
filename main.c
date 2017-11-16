/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:40:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/16 13:46:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_putendl("usage: ./fillit sample_file");
	else ((fd = open(argv[1], O_RDONLY)) != -1)
		ft_fillit(fd);
	else
		ft_putendl("error");
	return (0);
}
