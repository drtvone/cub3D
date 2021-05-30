/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:46:39 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/27 18:18:08 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **s)
{
	while (*s)
		free(*s++);
	free(s);
	return (NULL);
}

static size_t	ft_count(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (*s)
	{
		if (*s == c)
			n = 1;
		if (*s != c && n == 1)
		{
			n = 0;
			i++;
		}
		s++;
	}
	return (i);
}

static int	ft_check_c(char const *s, int start, char c)
{
	size_t	len;

	len = 0;
	while ((s[start]) && (s[start] != c))
	{
		len++;
		start++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;
	int		start;
	int		i;

	start = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	while (count-- > 0)
	{
		while (s[start] == c && s[start])
			start++;
		str[i] = ft_substr(s, start, ft_check_c(s, start, c));
		if (!str[i])
			return (ft_free(str));
		i++;
		start = start + ft_check_c(s, start, c);
	}
	str[i] = NULL;
	return (str);
}
