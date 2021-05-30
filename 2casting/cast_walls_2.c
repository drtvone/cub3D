#include "../cub3d.h"

void	select_texture(t_params *list, int	side, int	stepX, int	stepY)
{
	if (side == 0 && stepX == -1)
		list->buf = list->west;
	if (side == 0 && stepX == 1)
		list->buf = list->east;
	if (side == 1 && stepY == -1)
		list->buf = list->north;
	if (side == 1 && stepY == 1)
		list->buf = list->south;
}

void	calc_rays(t_params *list, int	x)
{
	double	camera;

	camera = 2 * x / (double)list->width - 1;
	list->rcst.raydirx = list->rays.dirX + list->rays.planeX * camera;
	list->rcst.raydiry = list->rays.dirY + list->rays.planeY * camera;
	list->rcst.deltadstx = fabs(1 / list->rcst.raydirx);
	list->rcst.deltadsty = fabs(1 / list->rcst.raydiry);
	list->rcst.mapx = (int)list->x;
	list->rcst.mapy = (int)list->y;
}

void	calc_step(t_params *list)
{
	if (list->rcst.raydirx < 0)
	{
		list->rcst.stepx = -1;
		list->rcst.sidedstx = (list->x - list->rcst.mapx) \
		* list->rcst.deltadstx;
	}
	else
	{
		list->rcst.stepx = 1;
		list->rcst.sidedstx = (list->rcst.mapx + 1.0 - list->x) \
		* list->rcst.deltadstx;
	}
	if (list->rcst.raydiry < 0)
	{
		list->rcst.stepy = -1;
		list->rcst.sidedsty = (list->y - list->rcst.mapy) \
		* list->rcst.deltadsty;
	}
	else
	{
		list->rcst.stepy = 1;
		list->rcst.sidedsty = (list->rcst.mapy + 1.0 - list->y) \
		* list->rcst.deltadsty;
	}
}
