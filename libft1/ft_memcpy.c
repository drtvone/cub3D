/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:00:50 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/26 23:18:35 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (i < n)
	{
		*ds++ = *sr++;
		i++;
	}
	return (dst);
}
