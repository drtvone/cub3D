/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:35:49 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/25 23:37:12 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *high, char *need, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*need)
		return ((char *)high);
	i = 0;
	while ((high[i]) && (i < len))
	{
		j = 0;
		while ((high[j]) && (high[i + j] == need[j]) && ((i + j) < len))
			j++;
		if (!need[j])
			return ((char *)&high[i]);
		i++;
	}
	return (0);
}
