/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:36:32 by rturnip           #+#    #+#             */
/*   Updated: 2021/01/27 14:28:49 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line1.h"

int	is_new_line(char *backup)
{
	int	i;

	i = 0;
	if (!backup)
		return (-1);
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	free(backup);
	return (-1);
}

int	ft_str_n(char *s, char *buf)
{
	int	i;

	i = 0;
	if (buf)
	{
		free(buf);
		return (-1);
	}
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_reborn_line(char *backup)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = is_new_line(backup);
	if (i < 0)
		return (0);
	temp = malloc(sizeof(char) * ((ft_strlen1(backup) - i) + 1));
	if (!temp)
		return (0);
	i++;
	while (backup[i])
		temp[j++] = backup[i++];
	temp[j] = '\0';
	free(backup);
	return (temp);
}

char	*ft_return_line(char *backup)
{
	size_t	i;
	char	*temp;

	i = 0;
	i = ft_strchr1(backup, '\n');
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (0);
	i = 0;
	while (backup[i] != '\n' && backup[i])
	{
		temp[i] = backup[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup;
	int			read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (!ft_str_n(backup, NULL) && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_str_n(NULL, buf));
		buf[read_bytes] = '\0';
		backup = ft_strjoin1(backup, buf);
	}
	free(buf);
	*line = ft_return_line(backup);
	backup = ft_reborn_line(backup);
	if (read_bytes == 0)
		return (0);
	return (1);
}
