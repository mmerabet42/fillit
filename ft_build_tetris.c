/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:43:43 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/18 23:14:52 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static t_tetri	*ft_build_tetri(t_list *lst, char b)
{
	char	*str;
	int		i;
	int		j;
	int		y;
	t_tetri	*tetri;

	y = 0;
	i = 0;
	j = 0;
	tetri = NULL;
	if (lst)
	{
		str = ft_strdup(lst->content);
		while (str[i])
		{
			if (str[i] == '\n')
				y++;
			if (str[i] == '#')
			{
				if (j > 3)
					return (NULL);
				if (j == 0)
					tetri = (t_tetri *)malloc(sizeof(t_tetri));
				tetri->c = b;
				tetri->pos.x = 0;
				tetri->pos.y = 0;
				tetri->points[j].x = i - 5 * (y);
				tetri->points[j].y = y;
				++j;
			}
			i++;
		}
	}
	if (j != 4)
		return (NULL);
	lst->content = tetri;
	return (tetri);
}

t_list	*ft_build_tetris(t_list *lst)
{
	char	c;
	t_tetri	*t;

	c = 'A';
	while (lst)
	{
		t = ft_build_tetri(lst, c);
		lst = lst->next;
	}
}

