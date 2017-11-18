/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:23:38 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/18 22:37:24 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	ft_d(int x, int y, int z, int t)
{
	if (x == z && t == y + 1)
		return (TRUE);
	return (FALSE);
}

static int	ft_r(int x, int y, int z, int t)
{
	if (x + 1 == z && t == y)
		return (TRUE);
	return (FALSE);
}

static void	ft_create_tab(int tab[4], t_tetri *tetri, char c)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (c == 'x')
			tab[i] = tetri->points[i].x;
		else
			tab[i] = tetri->points[i].y;
		++i;
	}
}

static t_bool	ft_valid_tetri(t_tetri *tetris)
{
	int		s;
	int		ytab[4];
	int		xtab[4];

	s = 0;
	ft_create_tab(xtab, tetris, 'x');
	ft_create_tab(ytab, tetris, 'y');
	s = ft_d(xtab[0], ytab[0], xtab[1], ytab[1]) +
		ft_d(xtab[0], ytab[0], xtab[2], ytab[2]) +
		ft_d(xtab[0], ytab[0], xtab[3], ytab[3]) +
		ft_d(xtab[1], ytab[1], xtab[2], ytab[2]) +
		ft_d(xtab[1], ytab[1], xtab[3], ytab[3]) +
		ft_d(xtab[2], ytab[2], xtab[3], ytab[3]) +
		ft_r(xtab[0], ytab[0], xtab[1], ytab[1]) +
		ft_r(xtab[0], ytab[0], xtab[2], ytab[2]) +
		ft_r(xtab[0], ytab[0], xtab[3], ytab[3]) +
		ft_r(xtab[1], ytab[1], xtab[2], ytab[2]) +
		ft_r(xtab[1], ytab[1], xtab[3], ytab[3]) +
		ft_r(xtab[2], ytab[2], xtab[3], ytab[3]);
	if (s >= 3)
		return (TRUE);
	else
		return (FALSE);
}

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
	if (ft_valid_tetri(tetri) == FALSE)
	{
		return (NULL);
	}
	return (tetri);
}

t_bool	ft_check_char(char *buf, int buffsize)
{
	int	i;

	i = 0;
	if (buffsize == 5)
	{
		while (i < 4)
		{
			if (buf[i] != '#' && buf[i] != '.')
				return (FALSE);
			++i;
		}
	}
	if (ft_strchr(buf, '\n') == buf + buffsize - 1)
		return (TRUE);
	return (FALSE);
}

char	*ft_list_tetris(char *str, char buf[6], int i, int *buffsize)
{
	if (i == 0)
		str = ft_strdup(buf);
	else if (i == 3)
	{
		str = ft_strjoin(str, buf);
		*buffsize = (*buffsize == 5 ? 1 : 5);
	}
	else if (i == 4)
		*buffsize = 5;
	else
		str = ft_strjoin(str, buf);
	return (str);
}

t_list	*ft_get_tetris(int fd)
{
	int		i;
	char	buf[6];
	int		buffsize;
	char	*str;
	t_list	*lst;
	t_list	*tmp;
	char	l;

	l = 'A';
	str = NULL;
	lst = NULL;
	i = 0;
	buffsize = 5;
	while (read(fd, buf, buffsize) == buffsize)
	{
		buf[buffsize] = '\0';
		if (ft_check_char(buf, buffsize) == FALSE)
			return (NULL);
			else
		{
			str = ft_list_tetris(str, buf, i, &buffsize);
			if (i == 3)
			{
				tmp = ft_lstpush(lst, ft_lstnew(str, 21));
				if (!lst)
					lst = tmp;
				str = NULL;
			}
			if (i != 4)
				++i;
			else
				i = 0;
			/*		if (i == 0)
					{
					str = ft_strdup(buf);
					++i;
					}
					else if (i == 3)
					{
					str = ft_strjoin(str, buf);
					tmp = ft_lstpush(lst, ft_lstnew(str, 21));
					if (lst == NULL)
					lst = tmp;
					(buffsize == 5) ? (buffsize = 1) : (buffsize = 5);
					str = NULL;
					++i;
					}
					else if (i == 4)
					{
					i = 0;
					buffsize = 5;
					}
					else
					{
					++i;
					str = ft_strjoin(str, buf);
					}
		*/}
	}
	tmp = lst;
	while (lst)
	{
		if (ft_build_tetri(lst, l++) == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (tmp);
}
