/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:58:38 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/27 17:27:10 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n') \
	|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	c;
	int	k;

	k = 0;
	c = 1;
	i = ft_space(str);
	if (str[i] == 45)
	{
		c = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] && str[i] > 47 && str[i] < 58)
	{
		k = (str[i] - 48) + k * 10;
		i++;
	}
	return (k * c);
}
