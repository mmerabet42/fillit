/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:40:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/20 22:13:48 by mmerabet         ###   ########.fr       */
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

void	brint(t_list *lst)
{
	t_tetri *t = (t_tetri *)lst->content;
	printf("tetris %c> x:%d, y:%d\n", t->c, t->pos.x, t->pos.y);
	int i = -1;
	while (++i < 4)
		printf("%d> x:%d, y:%d\n", i, t->points[i].x, t->points[i].y);
}

int			main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_putendl("usage: ./fillit sample_file");
	else if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		t_list	*lst;
		if ((lst = ft_get_tetris(fd)) == NULL)
			ft_putendl("KO");
		else
		{
			//lst = ft_absolute_tetris(lst);
			//ft_lstiter(lst, brint);
			t_mapdata *mapdata = ft_solve_tetris(lst);
			ft_print_map(mapdata);
			ft_putendl("OK");
		}
	}
	else
		ft_putendl("error");
	return (0);
}
