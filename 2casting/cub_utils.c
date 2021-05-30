#include "../cub3d.h"

void	init_struct(t_params *list)
{
	list->width = 0;
	list->height = 0;
	list->so_path = NULL;
	list->no_path = NULL;
	list->s_path = NULL;
	list->ea_path = NULL;
	list->we_path = NULL;
	list->floor_path = NULL;
	list->celing_path = NULL;
	list->params_fillment = 0;
	list->map = NULL;
	list->player = 0;
	list->check = 0;
}

void	fill_dir(t_all *all)
{
	if (all->point.vector == 'W')
	{
		all->list.rays.dirX = -1;
		all->list.rays.dirY = 0;
	}
	else if (all->point.vector == 'N')
	{
		all->list.rays.dirX = 0;
		all->list.rays.dirY = -1;
	}
	else if (all->point.vector == 'E')
	{
		all->list.rays.dirX = 1;
		all->list.rays.dirY = 0;
	}
	else
	{
		all->list.rays.dirX = 0;
		all->list.rays.dirY = 1;
	}
	all->list.rays.planeX = -0.66 * all->list.rays.dirY;
	all->list.rays.planeY = 0.66 * all->list.rays.dirX;
}

int	key_exit(t_all *all)
{
	all->spritenumb = 0;
	exit(0);
	return (0);
}
