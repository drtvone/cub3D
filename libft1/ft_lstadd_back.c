#include "libft.h"

void	ft_lstadd_back(t_list **cont, t_list *new)
{
	t_list	*last;

	if (*cont)
	{
		last = ft_lstlast(*cont);
		last->next = new;
	}
	else
		*cont = new;
}
