#include "../cub3d.h"

int	check_so_path(char *line, t_params *list)
{
	static char	**res;
	int			i;
	int			j;

	i = -1;
	j = 0;
	res = ft_split(line, ' ');
	if (res[2])
	{
		i = -1;
		if (res)
		{
			while (res[++i])
				free(res[i]);
			free(res);
		}
		return (0);
	}
	if (list->so_path != NULL)
		return (0);
	if ((res[0][0] == 'S') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->so_path = res[1];
	free(res[0]);
	free(res);
	return (1);
}

int	check_no_path(char *line, t_params *list)
{
	static char	**res;
	int			i;

	i = -1;
	res = ft_split(line, ' ');
	if (res[2] || list->no_path != NULL)
	{
		i = -1;
		if (res)
		{
			while (res[++i])
				free(res[i]);
			free(res);
		}
		return (0);
	}
	if ((res[0][0] == 'N') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->no_path = res[1];
	free(res[0]);
	free(res);
	return (1);
}

int	check_we_path(char *line, t_params *list)
{
	static char	**res;
	int			i;

	i = -1;
	res = ft_split(line, ' ');
	if (res[2] || list->we_path != NULL)
	{
		i = -1;
		if (res)
		{
			while (res[++i])
				free(res[i]);
			free(res);
		}
		return (0);
	}
	if ((res[0][0] == 'W') && (res[0][1] == 'E') && (res[0][2] == '\0'))
		list->we_path = res[1];
	free(res[0]);
	free(res);
	return (1);
}

int	check_ea_path(char *line, t_params *list)
{
	static char	**res;
	int			i;

	i = -1;
	res = ft_split(line, ' ');
	if (res[2] || list->ea_path != NULL)
	{
		i = -1;
		if (res)
		{
			while (res[++i])
				free(res[i]);
			free(res);
		}
		return (0);
	}
	if ((res[0][0] == 'E') && (res[0][1] == 'A') && (res[0][2] == '\0'))
		list->ea_path = res[1];
	free(res[0]);
	free(res);
	return (1);
}

int	check_s_path(char *line, t_params *list)
{
	static char	**res;
	int			i;

	i = -1;
	res = ft_split(line, ' ');
	if (res[2] || list->s_path != NULL)
	{
		i = -1;
		if (res)
		{
			while (res[++i])
				free(res[i]);
			free(res);
		}
		return (0);
	}
	if ((res[0][0] == 'S') && (res[0][1] == '\0'))
		list->s_path = res[1];
	free(res[0]);
	free(res);
	return (1);
}
