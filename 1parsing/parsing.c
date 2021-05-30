#include "../cub3d.h"

static int	check_resol_posit(char **res, t_params *list)
{
	int	width;
	int	heigth;

	width = ft_atoi(res[1]);
	heigth = ft_atoi(res[2]);
	if (width < 0 || heigth < 0)
		return (0);
	list->width = width;
	list->height = heigth;
	return (1);
}

static int	parse_resol(char **res, t_params *list, int i)
{
	if (res[3])
		return (0);
	if (ft_strchr(res[0], 'R') && (res[0][1] == '\0'))
	{
		while (res[1][++i])
			if (res[1][i] < '0' || res[1][i] > '9')
				return (0);
		i = -1;
		while (res[2][++i])
			if (res[2][i] < '0' || res[2][i] > '9')
				return (0);
	}
	check_resol_posit(res, list);
	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	return (1);
}

static int	check_resol(char *line, t_params *list)
{
	char	**res;
	int		i;

	i = -1;
	while (line[++i])
		if (!map_check_symb("0123456789 R", line[i]) || line[1] != ' ')
			return (0);
	i = -1;
	if (line[0] == 'R')
	{
		res = ft_split(line, ' ');
		return (parse_resol(res, list, i));
	}
	return (0);
}

int	check_params_fill(t_params *list)
{
	if (list->height && list->width \
	&& list->no_path && list->so_path \
	&& list->we_path && list->ea_path \
	&& list->floor_path && list->celing_path)
		list->params_fillment = 1;
	return (0);
}

int	check_params(char *line, t_params *list)
{
	if (ft_strnstr(line, "R", 1) != NULL)
		return (check_resol(line, list));
	else if (ft_strnstr(line, "SO", 2) != NULL)
		return (check_so_path(line, list));
	else if (ft_strnstr(line, "NO", 2) != NULL)
		return (check_no_path(line, list));
	else if (ft_strnstr(line, "EA", 2) != NULL)
		return (check_ea_path(line, list));
	else if (ft_strnstr(line, "WE", 2) != NULL)
		return (check_we_path(line, list));
	else if (ft_strnstr(line, "S", 1) != NULL)
		return (check_s_path(line, list));
	else if (ft_strnstr(line, "F", 1) != NULL)
		return (check_floor_path(line, list));
	else if (ft_strnstr(line, "C", 1) != NULL)
		return (check_celing_path(line, list));
	return (1);
}
