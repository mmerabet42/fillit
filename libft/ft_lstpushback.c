// ADD HEADER
#include "libft.h"

t_list				*ft_lstpushback(t_list *lst,
								void *content,
								size_t content_size)
{
	return (ft_lstpush(lst, ft_lstcreate(content, content_size)));
}
