#include "../cub3d.h"

int	skip_symb(char *line, int	i)
{
	while (line[i] == ' ')
		i++;
	if (line[i] == ',')
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	skip_one_symb(char *line, int i, int c)
{
	if (line[i] == c)
		return (1);
	return (0);
}

void	make_nbr(char *line, int *r)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		r[0] = r[0] * 10 + line[i++] - 48;
	i = skip_symb(line, i);
	while (line[i] >= '0' && line[i] <= '9')
		r[1] = r[1] * 10 + line[i++] - 48;
	i = skip_symb(line, i);
	while (line[i] >= '0' && line[i] <= '9')
		r[2] = r[2] * 10 + line[i++] - 48;
}

int	check_floor_path(char *line, t_params *list)
{
	int	i;
	int	r[3];

	i = 0;
	if (list->floor_path != NULL)
		return (0);
	i = -1;
	while (line[++i])
		if (!map_check_symb("0123456789, F", line[i]) || line[1] != ' ')
			return (0);
	r[0] =0;
	r[1] = 0;
	r[2] = 0;
	make_nbr(line, r);
	list->floor_path = "1";
	if (r[0] > 255 || r[1] > 255 || r[2] > 255)
		return (0);
	list->floorclr = createRGB(r[0], r[1], r[2]);
	return (1);
}

int	check_celing_path(char *line, t_params *list)
{
	int	i;
	int	r[3];

	i = 0;
	if (list->celing_path != NULL)
		return (0);
	i = -1;
	while (line[++i])
		if (!map_check_symb("0123456789, C", line[i]) || line[1] != ' ')
			return (0);
	r[0] =0;
	r[1] = 0;
	r[2] = 0;
	make_nbr(line, r);
	list->celing_path = "1";
	if (r[0] > 255 || r[1] > 255 || r[2] > 255)
		return (0);
	list->celingclr = createRGB(r[0], r[1], r[2]);
	return (1);
}
