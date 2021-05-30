/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:17:21 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/27 18:19:53 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_fill(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*rez;

	k = 0;
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	rez = (char *)malloc(sizeof(char) * (i + 1));
	if (!rez)
	{
		free(rez);
		return (NULL);
	}
	i = -1;
	while (((char *)s1)[++i])
		rez[i] = ((char *)s1)[i];
	while (((char *)s2)[k])
		rez[i++] = ((char *)s2)[k++];
	rez[i] = '\0';
	return (rez);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rez;
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	rez = ft_fill(s1, s2);
	return (rez);
}
