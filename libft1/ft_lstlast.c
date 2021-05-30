#include "libft.h"

t_list	*ft_lstlast(t_list *cont)
{
	while (cont)
	{
		if (!cont->next)
			return (cont);
		cont = cont->next;
	}
	return (cont);
}
