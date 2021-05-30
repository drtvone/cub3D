/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:37:29 by rturnip           #+#    #+#             */
/*   Updated: 2021/01/27 14:39:13 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line1.h"

size_t	ft_strlen1(const char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr1(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strdup1(char *s1)
{
	size_t		size;
	int			i;
	char		*s2;

	if (!s1)
		return (NULL);
	size = ft_strlen1(s1) + 1;
	i = 0;
	s2 = (char *)malloc(size * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_norm1(char *s1, char *s2)
{
	if (!s1)
		return (ft_strdup1(s2));
	else
		return (ft_strdup1(s1));
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	len;
	char	*rez;
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!(s1) || !(s2))
		return (ft_norm1(s1, s2));
	len = ft_strlen1((char *)s1) + ft_strlen1((char *)s2);
	rez = (char *)malloc(sizeof(char) * (len + 1));
	if (!rez)
		return (NULL);
	while (((char *)s1)[i])
	{
		rez[i] = ((char *)s1)[i];
		i++;
	}
	while (((char *)s2)[k])
		rez[i++] = ((char *)s2)[k++];
	rez[i] = '\0';
	free(s1);
	return (rez);
}
