/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:23:38 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/16 17:43:04 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	int	ret;
	char	buf[5];
	int		buffsize;
	char	*str;

	str = NULL;
	i = 0;
	buffsize = 5;
	while ((ret = read(fd, buf, buffsize) == buffsize))
	{
		buf[ret] = '\0';
		if (ft_check_tetris(buf, buffsize == FALSE))
			return (NULL);
		else
		{
			if (str == NULL)
				str = buf;
			else
			{
				str = ft_strjoin(str, buf);
			}
			(buffsize == 5) ? (buffsize = 1) : (buffsize = 5);
		}
	}
}

int	main(char **argv)
{
	fd = open(argv[1], O_RDONLY);
	printf("%s\n", ft_get_tetris(fd);
			return (0);
}
