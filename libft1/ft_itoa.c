/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:10:18 by rturnip           #+#    #+#             */
/*   Updated: 2020/11/27 16:56:04 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count = 1;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

static void	ft_rev(char *itoa)
{
	size_t	i;
	size_t	len;
	char	one;

	i = 0;
	len = ft_strlen(itoa) - 1;
	while (i < len)
	{
		one = itoa[i];
		itoa[i] = itoa[len];
		itoa[len] = one;
		i++;
		len--;
	}
}

static void	ft_make_str(int n, char *itoa)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	if (n < 0)
	{
		n = -n;
		k = -1;
	}
	while (n > 0)
	{
		itoa[i++] = n % 10 + 48;
		n = n / 10;
	}
	if (k == -1)
		itoa[i] = '-';
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	i;
	size_t	count;

	i = 0;
	itoa = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_count(n);
	itoa = malloc(sizeof(char) * (count + 1));
	if (!itoa)
		return (NULL);
	itoa[count] = '\0';
	ft_make_str(n, itoa);
	if (n == 0)
		itoa[i++] = '0';
	ft_rev(itoa);
	return (itoa);
}
