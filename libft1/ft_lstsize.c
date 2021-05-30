#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int	k;

	k = 0;
	while (list)
	{
		list = list->next;
		k++;
	}
	return (k);
}
