/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:40:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/19 16:51:04 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>

t_list		*ft_get_tetris(int fd)
{
	t_list	*lst;
	char	buf[6];
	int		buffsize;
	int		i;

	i = 0;
	buffsize = 5;
	lst = ft_read_tetris(fd, buf, buffsize, i);
	if (!lst)
		return (NULL);
	if (ft_build_tetris(lst) == FALSE)
		return (NULL);
	if (ft_valid_tetris(lst) == FALSE)
		return (NULL);
	return (lst);
}

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
