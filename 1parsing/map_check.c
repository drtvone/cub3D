#include "../cub3d.h"

int	map_check_symb(char *str, int	c)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

static int	map_check_around(char **map, char *comp, int	i, int	j)
{
	if (map_check_symb(comp, map[i - 1][j]) \
	&& map_check_symb(comp, map[i + 1][j]) \
	&& map_check_symb(comp, map[i][j + 1]) \
	&& map_check_symb(comp, map[i][j - 1]) \
	&& map_check_symb(comp, map[i + 1][j + 1]) \
	&& map_check_symb(comp, map[i + 1][j - 1]) \
	&& map_check_symb(comp, map[i - 1][j - 1]) \
	&& map_check_symb(comp, map[i - 1][j + 1]))
		return (1);
	return (0);
}

static void	player_position(char **map, int i, int j, t_all *all)
{
	if (all->list.player == 1)
	{
		printf("\n ERROR in the map\n");
		exit (0);
	}
	all->list.player = 1;
	if (!(map_check_around(map, "012", i, j)))
	{
		printf("\n ERROR in the map\n");
		exit (0);
	}
	all->list.x = j + 0.5;
	all->list.y = i + 0.5;
	all->point.vector = map[i][j];
}

static int	sprite_pos(t_all *all, int n, int i, int j)
{
	all->sprite[n].y = i + 0.5;
	all->sprite[n].x = j + 0.5;
	n++;
	return (n);
}

int	map_checker(char **map, t_params *list, t_all *all)
{
	int		i;
	int		j;
	int		n;

	i = -1;
	n = 0;
	all->sprite = malloc(sizeof(t_sprite) * all->spritenumb);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(map_check_symb(" 1NWSE02", map[i][j])))
				return (0);
			if (map_check_symb("NWSE", map[i][j]))
				player_position(map, i, j, all);
			if (map[i][j] == '2')
				n = sprite_pos(all, n, i, j);
			if (map[i][j] == '0' && !(map_check_around(map, "120NSWE", i, j)))
				return (0);
		}
	}
	if (list->player == 0)
		return (0);
	return (1);
}
