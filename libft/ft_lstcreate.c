// ADD HEADER
#include "libft.h"

t_list	*ft_lstcreate(void *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		lst->content = content;
		lst->content_size = (content ? content_size : 0);
	}
	return (lst);
}
