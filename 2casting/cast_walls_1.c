#include "../cub3d.h"

void	check_hit(t_params *list)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (list->rcst.sidedstx < list->rcst.sidedsty)
		{
			list->rcst.sidedstx += list->rcst.deltadstx;
			list->rcst.mapx += list->rcst.stepx;
			list->rcst.side = 0;
		}
		else
		{
			list->rcst.sidedsty += list->rcst.deltadsty;
			list->rcst.mapy += list->rcst.stepy;
			list->rcst.side = 1;
		}
		if (list->map[list->rcst.mapy][list->rcst.mapx] == '1')
			hit = 1;
	}
}

void	calc_start_end1(t_params *list)
{
	if (list->rcst.side == 0 && list->rcst.raydirx > 0)
		list->rcst.texx = TEXWIDTH - list->rcst.texx - 1;
	if (list->rcst.side == 1 && list->rcst.raydiry < 0)
		list->rcst.texx = TEXWIDTH - list->rcst.texx - 1;
	list->rcst.texx = 64 - list->rcst.texx -1;
}

void	calc_start_end(t_params *list, int	x)
{
	double	perpdist;

	if (list->rcst.side == 0)
		perpdist = (list->rcst.mapx - list->x + \
		(1 - list->rcst.stepx) / 2) / list->rcst.raydirx;
	else
		perpdist = (list->rcst.mapy - list->y + \
		(1 - list->rcst.stepy) / 2) / list->rcst.raydiry;
	list->rcst.lineheight = (int)(list->height / perpdist);
	list->rcst.drawstart = list->height / 2 - \
	list->rcst.lineheight / 2;
	if (list->rcst.drawstart < 0)
		list->rcst.drawstart = 0;
	list->rcst.drawend = list->rcst.lineheight / \
	2 + list->height / 2;
	if (list->rcst.drawend >= list->height)
		list->rcst.drawend = list->height - 1;
	if (list->rcst.side == 0)
		list->rcst.wallx = list->y + perpdist * list->rcst.raydiry;
	else
		list->rcst.wallx = list->x + perpdist * list->rcst.raydirx;
	list->rcst.wallx -= floor(list->rcst.wallx);
	list->rays.zBuffer[x] = perpdist;
	list->rcst.texx = (int)(list->rcst.wallx * (double)(TEXWIDTH));
	calc_start_end1(list);
}

void	put_wall_pixels(t_params *list, int	x)
{
	double	step;
	double	texpos;
	int		k;
	int		texy;
	int		color;

	k = 0;
	step = 1.0 * TEXWIDTH / list->rcst.lineheight;
	texpos = (list->rcst.drawstart - list->height / \
	2 + list->rcst.lineheight / 2) * step;
	select_texture(list, list->rcst.side, list->rcst.stepx, list->rcst.stepy);
	while (k++ < list->rcst.drawstart)
		my_mlx_pixel_put(list, x, k, list->celingclr);
	k = list->rcst.drawend;
	while (k++ < list->height - 1)
		my_mlx_pixel_put(list, x, k, list->floorclr);
	while (list->rcst.drawstart++ < list->rcst.drawend -1)
	{
		texy = (int)texpos & (TEXHEIGHT - 1);
		texpos += step;
		color = *(unsigned int *)(list->buf.addr + (texy * \
		list->buf.line_len + list->rcst.texx * \
		(list->buf.bpp / 8)));
		my_mlx_pixel_put(list, x, list->rcst.drawstart, color);
	}	
}

void	draw_ray_lodev(t_params *list)
{
	int	x;

	x = 0;
	list->rcst.raydirx = 0;
	list->rcst.raydiry = 0;
	list->rays.zBuffer = (double *)malloc(sizeof(double) * list->width);
	while (x < list->width)
	{
		calc_rays(list, x);
		calc_step(list);
		check_hit(list);
		calc_start_end(list, x);
		put_wall_pixels(list, x);
		x++;
	}
}
