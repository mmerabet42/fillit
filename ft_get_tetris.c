/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:23:38 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/16 19:22:51 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void	brint(t_list *lst)
{
	printf("%s\n", lst->content);
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
	if (ft_strchr(buf, '\n') == buf + buffsize -1 )
		return (TRUE);
	else 
		return (FALSE);
}

t_list	*ft_get_tetris(int fd)
{
	int	i;
	char	buf[5];
	int		buffsize;
	char	*str;
	t_list	*lst;

	str = NULL;
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
				i = 0;
				str = ft_strjoin(str, buf);
				ft_lstpush(lst, ft_lstnew(str, 21));
				(buffsize == 5) ? (buffsize = 1) : (buffsize = 5);
				str = NULL;
			}
			else
			{
				++i;
				str = ft_strjoin(str, buf);
			}
		}
	}
	ft_lstiter(lst, brint);
	return (NULL);
}
