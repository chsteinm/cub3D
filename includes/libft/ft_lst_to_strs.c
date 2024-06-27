#include "libft.h"

char	**ft_lst_to_strs(t_list *lst)
{
	char	**strs;
	size_t	i;

	strs = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (lst)
	{
		strs[i++] = lst->content;
		lst = lst->next;
	}
	return (strs);
}