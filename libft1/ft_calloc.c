/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:13:49 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/26 14:00:52 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = malloc(size * count);
	if (!a)
		return (NULL);
	while (i < size * count)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
