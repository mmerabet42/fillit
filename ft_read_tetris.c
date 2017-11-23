/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:44:21 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/23 11:17:04 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	ft_check_char(char *buf, int buffsize)
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

static char		*ft_list_tetris(char *str, char buf[6], int i, int *buffsize)
{
	char	*tmp;

	tmp = str;
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
	if (tmp)
		free(tmp);
	return (str);
}

t_list			*ft_read_tetris(int fd, char buf[6], int buffsize, int i)
{
	char	*str;
	t_list	*lst;
	t_list	*tmp;

	str = NULL;
	lst = NULL;
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
				lst = ((!lst) ? tmp : lst);
				str = NULL;
			}
			i = ((i != 4) ? ++i : 0);
		}
	}
	return ((buffsize == 1) ? lst : NULL);
}
