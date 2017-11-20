/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:40:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/20 22:03:48 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

void	brint(t_list *lst)
{
	t_tetri *t = (t_tetri *)lst->content;
	printf("tetris> x:%d, y:%d\n", t->pos.x, t->pos.y);
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
		t_tetri	a = ft_new_tetri('A', 0, 0,	1, 0,	2, 0,	0, 1,	1, 1);
		t_tetri	b = ft_new_tetri('B', 0, 0,	0, 0,	1, 0,	0, 1,	1, 1);
		t_tetri	c = ft_new_tetri('C', 0, 0,	0, 0,	0, 1,	1, 1,	1, 2);
		t_tetri	d = ft_new_tetri('D', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	e = ft_new_tetri('E', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	f = ft_new_tetri('F', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	g = ft_new_tetri('G', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	h = ft_new_tetri('H', 0, 0,	1, 0,	2, 0,	0, 1,	1, 1);
		t_tetri	i = ft_new_tetri('I', 0, 0,	0, 0,	1, 0,	0, 1,	1, 1);
		t_tetri	j = ft_new_tetri('J', 0, 0,	0, 0,	0, 1,	1, 1,	1, 2);
		t_tetri	k = ft_new_tetri('K', 0, 0,	1, 0,	2, 0,	0, 1,	1, 1);
		t_tetri	l = ft_new_tetri('L', 0, 0,	0, 0,	1, 0,	0, 1,	1, 1);
		t_tetri	m = ft_new_tetri('M', 0, 0,	0, 0,	0, 1,	1, 1,	1, 2);
		t_tetri	n = ft_new_tetri('N', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	o = ft_new_tetri('O', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	p = ft_new_tetri('P', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	q = ft_new_tetri('Q', 0, 0,	0, 0,	0, 1,	0, 2,	1, 2);
		t_tetri	r = ft_new_tetri('R', 0, 0,	1, 0,	2, 0,	0, 1,	1, 1);
		t_tetri	s = ft_new_tetri('S', 0, 0,	0, 0,	1, 0,	0, 1,	1, 1);
		t_tetri	t = ft_new_tetri('T', 0, 0,	0, 0,	0, 1,	1, 1,	1, 2);
		t_list	*lst = ft_lstnew(&a, sizeof(t_tetri));
		ft_lstpush(lst, ft_lstnew(&b, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&c, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&d, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&e, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&f, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&g, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&h, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&i, sizeof(t_tetri)));
		/*ft_lstpush(lst, ft_lstnew(&j, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&k, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&l, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&m, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&n, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&o, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&p, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&q, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&r, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&s, sizeof(t_tetri)));
		ft_lstpush(lst, ft_lstnew(&t, sizeof(t_tetri)));*/
		t_mapdata	*map = ft_solve_tetris(lst);
		ft_print_map(map);
	}
	else
		ft_putendl("error");
	return (0);
}
