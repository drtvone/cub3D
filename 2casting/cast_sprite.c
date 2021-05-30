#include "../cub3d.h"

void	sort_sprites(t_all *all, int	*spriteOrder, double *spriteDistance)
{
	int		i;
	int		j;
	int		min;
	int		temp1;
	double	temp2;

	j = 0;
	while (j < all->spritenumb)
	{
		i = j;
		min = j;
		while (i < all->spritenumb)
		{
			if (spriteDistance[i] > spriteDistance[min])
				min = i;
			i++;
		}
		temp1 = spriteOrder[j];
		temp2 = spriteDistance[j];
		spriteDistance[j] = spriteDistance[min];
		spriteOrder[j] = spriteOrder[min];
		spriteDistance[min] = temp2;
		spriteOrder[min] = temp1;
		j++;
	}
}

void	calc_sprite_order(t_all *all)
{
	int	i;

	i = -1;
	all->scst.spriteorder = malloc(sizeof(int) * all->spritenumb);
	all->scst.spritedist = malloc(sizeof(double) * all->spritenumb);
	while (++i < all->spritenumb)
	{
		all->scst.spriteorder[i] = i;
		all->scst.spritedist[i] = ((all->list.x - all->sprite[i].x) * \
		(all->list.x - all->sprite[i].x) + (all->list.y - all->sprite[i].y) * \
		(all->list.y - all->sprite[i].y));
	}
}

void 	calc_sprite_xy(t_all *all, int	i)
{
	double	invdet;

	all->scst.spritex = all->sprite[all->scst.spriteorder[i]].x - all->list.x;
	all->scst.spritey = all->sprite[all->scst.spriteorder[i]].y - all->list.y;
	invdet = 1.0 / (all->list.rays.planeX * all->list.rays.dirY - \
	all->list.rays.dirX * all->list.rays.planeY);
	all->scst.transformx = invdet * (all->list.rays.dirY * all->scst.spritex - \
	all->list.rays.dirX * all->scst.spritey);
	all->scst.transformy = invdet * ((-all->list.rays.planeY) * all->scst.spritex + \
	all->list.rays.planeX * all->scst.spritey);
	all->scst.spritescreenx = (int)((all->list.width / 2) * \
	(1 + all->scst.transformx / all->scst.transformy));
	all->scst.spriteheight = abs((int)(all->list.height / \
	all->scst.transformy));
}

void	calc_start_end_sprite(t_all *all)
{
	all->scst.drawstarty = all->list.height / 2 - all->scst.spriteheight / 2;
	if (all->scst.drawstarty < 0)
		all->scst.drawstarty = 0;
	all->scst.drawendy = all->scst.spriteheight / 2 + all->list.height / 2;
	if (all->scst.drawendy >= all->list.height)
		all->scst.drawendy = all->list.height - 1;
	all->scst.spritewidth = abs((int)(all->list.height / all->scst.transformy));
	all->scst.drawstartx = all->scst.spritescreenx - all->scst.spritewidth / 2;
	if (all->scst.drawstartx < 0)
		all->scst.drawstartx = 0;
	all->scst.drawendx = all->scst.spritescreenx + all->scst.spritewidth / 2;
	if (all->scst.drawendx >= all->list.width)
		all->scst.drawendx = all->list.width - 1;
}

void	put_sprite_draw(t_all *all, int	texx, int texy, int	stripe)
{
	int	y;
	int	d;

	stripe = all->scst.drawstartx;
	while (stripe++ < all->scst.drawendx -1)
	{
		texx = (int)((256 * (stripe - (all->scst.spritescreenx - \
		all->scst.spritewidth / 2)) * TEXWIDTH / all->scst.spritewidth) / 256);
		if (all->scst.transformy > 0 && stripe > 0 && stripe < all->list.width && \
			all->scst.transformy < all->list.rays.zBuffer[stripe])
		{
			y = all->scst.drawstarty;
			while (y++ < all->scst.drawendy -1)
			{
				d = y * 256 - all->list.height * 128 + \
				all->scst.spriteheight * 128;
				texy = ((d * TEXHEIGHT) / all->scst.spriteheight) / 256;
				d = *(unsigned int *)(all->sprtimg.addr + (texy * \
				all->sprtimg.line_len + texx * \
				(all->sprtimg.bpp / 8)));
				if (d != 0x000000)
					my_mlx_pixel_put(&all->list, stripe, y, d);
			}
		}
	}
}
