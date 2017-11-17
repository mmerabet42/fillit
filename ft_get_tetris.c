/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:23:38 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/17 22:54:29 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

# define TP tetris->points

static void	brint(t_list *lst)
{
	ft_putendl(lst->content);
}

static int	ft_check_down(int x, int y, int z, int t)
{
		/*ft_putnbr(x);
		ft_putchar(';');
		ft_putnbr(y);
		ft_putchar(10);
		ft_putnbr(z);
		ft_putchar(';');
		ft_putnbr(t);
		ft_putchar(10);*/
	if (x == z && t == y + 1)
		return (TRUE);
	return (FALSE);
}

static int	ft_check_right(int x, int y, int z, int t)
{
		/*ft_putnbr(x);
		ft_putchar(';');
		ft_putnbr(y);
		ft_putchar(10);
		ft_putnbr(z);
		ft_putchar(';');
		ft_putnbr(t);
		ft_putchar(10);*/
	if (x + 1 == z && t == y)
	{
		//ft_putstr("x + 1 == z && t == y");
		return (TRUE);
	}
	return (FALSE);
}
static t_bool	ft_check_pos(t_tetri *tetris)
{
	int		i;
	int		s;
	int		c;
	int		d;

	i = 0;
	s = 0;
	c = 0;
	d = 0;
	while (i < 3)
	{
		/*ft_putstr("i = ");
		ft_putnbr(i);
		ft_putchar(10);*/
		c = ft_check_down(TP[i].x, TP[i].y, TP[i + 1].x, TP[i + 1].y);
		c = ft_check_down(TP[i].x, TP[i].y, TP[i + 2].x, TP[i + 2].y) + c;
		c = ft_check_down(TP[i].x, TP[i].y, TP[i + 3].x, TP[i + 3].y) + c;
		d = ft_check_right(TP[i].x, TP[i].y, TP[i + 1].x, TP[i + 1].y);
		d = ft_check_right(TP[i].x, TP[i].y, TP[i + 2].x, TP[i + 2].y) + d;
		d = ft_check_right(TP[i].x, TP[i].y, TP[i + 3].x, TP[i + 3].y) + d;
		s = s + c + d;
	/*	ft_putnbr(c);
		ft_putchar(10);
		ft_putnbr(d);
		ft_putchar(10);
		ft_putnbr(s);
		ft_putchar(10);*/
		++i;
	}
	//ft_putnbr(s);
	//ft_putchar(10);
	if (s >= 3)
		return (TRUE);
	else
		return (FALSE);
}
static t_tetri	*ft_build_tetris(t_list *lst, char b)
{
	char *str;
	int		i;
	int		j;
	int		y;
	t_tetri	*tetris;

	y = 0;
	i = 0;
	j = 0;
	tetris = NULL;
	if (lst)
	{
		str = ft_strdup(lst->content);
		while (str[i])
		{
			if(str[i] == '\n')
				y++;
			if (str[i] == '#')
			{
				if (j > 3)
					return (NULL);
				if (j == 0)
					tetris = (t_tetri *)malloc(sizeof(t_tetri));
				tetris->c = b;
				tetris->pos.x = 0;
				tetris->pos.y = 0;
				tetris->points[j].x = i - 5 * (y);
				tetris->points[j].y = y;
				++j;
			}
			i++;
		}
	}

	if (j != 4)
		return (NULL);
	if (ft_check_pos(tetris) == FALSE)
	{
		return (NULL);
	}
	return (tetris);
}

t_bool	ft_check_tetris(char *buf, int buffsize)
{
	int	i;

	i = 0;
	if (buffsize == 5)
	{
		while (i < 3)
		{
			if (buf[i] != '#' || buf[i] != '.')
				return (FALSE);
			i++;
		}
	}
	if (ft_strchr(buf, '\n') == buf + buffsize - 1)
		return (TRUE);
	else 
		return (FALSE);
}

t_list	*ft_get_tetris(int fd)
{
	int	i;
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
		if (ft_check_tetris(buf, buffsize == FALSE))
			return (NULL);
		else
		{
			if (i == 0)
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
		}
	}
	tmp = lst;
	while (lst)
	{
		if (ft_build_tetris(lst, l++) == NULL)
			return (NULL);
		lst = lst->next;
	}
	//ft_lstiter(tmp, brint);
	return (tmp);
}
