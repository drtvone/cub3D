/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:51:08 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/26 23:36:15 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	t;

	i = 0;
	t = ft_strlen(dst);
	k = ft_strlen((char *)src);
	if (!dstsize)
		return (k);
	if (t > dstsize)
		return (k + dstsize);
	k = t + k;
	while (t < dstsize - 1 && src[i])
		dst[t++] = src[i++];
	dst[t] = '\0';
	return (k);
}
