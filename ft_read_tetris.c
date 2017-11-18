/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:44:21 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/18 22:45:07 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

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

t_list	*ft_read_tetris(int fd)
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
