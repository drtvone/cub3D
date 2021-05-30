/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:43:04 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/26 23:30:37 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	const char	*h;

	len = ft_strlen(s);
	h = (char *)s + len;
	while (len--)
	{
		if (*h == (char)c)
			return ((char *)h);
		h--;
	}
	if (*h == (char)c)
		return ((char *)h);
	return (NULL);
}
