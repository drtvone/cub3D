/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:54:52 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/26 23:26:26 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sour;
	char		*ddd;
	const char	*sss;

	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	sour = (const char *)src;
	if (dst < src)
	{
		while (len--)
		{
			*dest++ = *sour++;
		}
	}
	else
	{
		ddd = dest + (len - 1);
		sss = sour + (len - 1);
		while (len--)
			*ddd-- = *sss--;
	}
	return (dst);
}
