/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:54:08 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/26 23:37:09 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (length >= len)
		length = len;
	sub = malloc(sizeof(char) * length + 1);
	if (sub == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (sub);
	while (i < len)
	{
		sub[i] = (char)s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
