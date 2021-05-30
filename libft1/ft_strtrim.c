/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:29:12 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/26 23:32:45 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trim;
	int		k;

	k = 0;
	if ((!s1) || (!set))
		return (NULL);
	while ((*s1) && (ft_strchr(set, *s1)))
		s1++;
	len = ft_strlen(s1);
	while ((len) && (ft_strchr(set, s1[len])))
		len--;
	trim = ft_substr(s1, 0, len + 1);
	return ((char *)trim);
}
