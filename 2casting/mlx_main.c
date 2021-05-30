#include "../cub3d.h"

void	key_ws(int	key, t_all *all)
{
	if (key == W)
	{
		if (all->list.map[(int)(all->list.y)][(int)(all->list.x \
		+ all->list.rays.dirX * MVSPEED)] != '1')
			all->list.x += all->list.rays.dirX * MVSPEED;
		if (all->list.map[(int)(all->list.y + all->list.rays.dirY \
		* MVSPEED)][(int)(all->list.x)] != '1')
			all->list.y += all->list.rays.dirY * MVSPEED;
	}
	if (key == S)
	{
		if (all->list.map[(int)(all->list.y)][(int)(all->list.x - \
		all->list.rays.dirX * MVSPEED)] != '1')
			all->list.x -= all->list.rays.dirX * MVSPEED;
		if (all->list.map[(int)(all->list.y - all->list.rays.dirY * \
		MVSPEED)][(int)(all->list.x)] != '1')
			all->list.y -= all->list.rays.dirY * MVSPEED;
	}
}

void	key_left_right(int	key, t_all *all, double odirx, double oplanex)
{
	if (key == LEFT)
	{
		odirx = all->list.rays.dirX;
		all->list.rays.dirX = all->list.rays.dirX * \
		cos(-MVROTATE) - all->list.rays.dirY * sin(-MVROTATE);
		all->list.rays.dirY = odirx * sin(-MVROTATE) + \
		all->list.rays.dirY * cos(-MVROTATE);
		oplanex = all->list.rays.planeX;
		all->list.rays.planeX = all->list.rays.planeX * \
		cos(-MVROTATE) - all->list.rays.planeY * sin(-MVROTATE);
		all->list.rays.planeY = oplanex * sin(-MVROTATE) + \
		all->list.rays.planeY * cos(-MVROTATE);
	}
}

void	key_da(int	key, t_all *all)
{
	if (key == D)
	{
		if (all->list.map[(int)(all->list.y)][(int)(all->list.x \
		+ all->list.rays.planeX / (1 / 0.66) * MVSPEED)] != '1')
			all->list.x += all->list.rays.planeX / (1 / 0.66) * MVSPEED;
		if (all->list.map[(int)(all->list.y + all->list.rays.planeY \
		/ (1 / 0.66) * MVSPEED)][(int)(all->list.x)] != '1')
			all->list.y += all->list.rays.planeY / (1 / 0.66) * MVSPEED;
	}
	if (key == A)
	{
		if (all->list.map[(int)(all->list.y)][(int)(all->list.x - \
		all->list.rays.planeX / (1 / 0.66) * MVSPEED)] != '1')
			all->list.x -= all->list.rays.planeX / (1 / 0.66) * MVSPEED;
		if (all->list.map[(int)(all->list.y - all->list.rays.planeY \
		/ (1 / 0.66) * MVSPEED)][(int)(all->list.x)] != '1')
			all->list.y -= all->list.rays.planeY / (1 / 0.66) * MVSPEED;
	}
}

int	key_holds(int	key, t_all *all)
{
	double	odirx;
	double	oplanex;

	odirx = 0;
	oplanex = 0;
	key_ws(key, all);
	key_left_right(key, all, odirx, oplanex);
	if (key == RIGHT)
	{
		odirx = all->list.rays.dirX;
		all->list.rays.dirX = all->list.rays.dirX * \
		cos(MVROTATE) - all->list.rays.dirY * sin(MVROTATE);
		all->list.rays.dirY = odirx * sin(MVROTATE) + \
		all->list.rays.dirY * cos(MVROTATE);
		oplanex = all->list.rays.planeX;
		all->list.rays.planeX = all->list.rays.planeX * \
		cos(MVROTATE) - all->list.rays.planeY * sin(MVROTATE);
		all->list.rays.planeY = oplanex * sin(MVROTATE) + \
		all->list.rays.planeY * cos(MVROTATE);
	}
	key_da(key, all);
	if (key == 53)
		exit(0);
	main_draw(all);
	return (0);
}

void	init_mlx_main(t_all *all)
{
	int	mlx_h;
	int	mlx_w;

	all->list.mlx = mlx_init();
	mlx_get_screen_size(all->list.mlx, &mlx_w, &mlx_h);
	if (all->list.width > mlx_w)
		all->list.width = mlx_w;
	if (all->list.height > mlx_h)
		all->list.height = mlx_h;
	all->list.win = mlx_new_window(all->list.mlx, \
	all->list.width, all->list.height, "first");
	load_image(&all->list);
	load_image_2(&all->list);
	load_image_3(&all->list);
	load_image_4(&all->list);
	load_image_5(all);
	main_draw(all);
	mlx_hook(all->list.win, 2, 1L << 0, &key_holds, all);
	mlx_hook(all->list.win, 17, 0L, &key_exit, all);
	mlx_loop(all->list.mlx);
}
