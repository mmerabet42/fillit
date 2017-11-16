/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:23:38 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/16 18:27:47 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

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
	if (ft_strchr(buf, '\n') == buf[buffsize])
		return (TRUE);
	else 
		return (FALSE);
}

t_list	*ft_get_tetris(int fd)
{
	int	i;
	char	buf[5];
	int		buffsize;
	t_list	*lst;
	char	*str;

	buffsize = 5;
	i = 0;
	while (read(fd, buf, buffsize) == buffsize)
	{
		str = NULL;
		if (ft_check_tetris(buf, buffsize) == FALSE)
			return (NULL);
		else
		{
			if (i == 0)
			{
				str = buf;
				++i;
			}
			else if (i == 3)
			{
				i = 0;
				str = ft_strjoin(buf, str);
				lst
				(buffsize == 5) ? (buffsize = 1) : (buffsize = 5);
			}
			else
			{
				str = ft_strjoin(buf, str);
				++i;
			}
		}
	}
}
