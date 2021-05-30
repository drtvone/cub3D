#include "../cub3d.h"

int	draw_sprites(t_all *all)
{
	int	i;
	int	texy;
	int	texx;
	int	stripe;

	texx = 0;
	texy = 0;
	stripe = 0;
	calc_sprite_order(all);
	sort_sprites(all, all->scst.spriteorder, all->scst.spritedist);
	i = -1;
	while (++i < all->spritenumb)
	{
		calc_sprite_xy(all, i);
		calc_start_end_sprite(all);
		put_sprite_draw(all, texx, texy, stripe);
	}
	free(all->scst.spriteorder);
	free(all->scst.spritedist);
	free(all->list.rays.zBuffer);
	return (0);
}

void	head(int	fd, t_all *all, int	res, int	size)
{
	char	header[54];

	ft_bzero(header, 54);
	header[0] = 0x42;
	header[1] = 0x4D;
	ft_memcpy(&header[2], &size, 4);
	header[10] = 0x36;
	header[14] = 0x28;
	ft_memcpy(&header[18], &res, 4);
	res = -all->list.height;
	ft_memcpy(&header[22], &res, 4);
	header[26] = 0x01;
	header[28] = 0x20;
	write(fd, header, 54);
}

void	screenshot(t_all *all)
{
	int	fd;
	int	res;
	int	size;

	res = all->list.width;
	size = 54 + (all->list.width * all->list.height) * 4;
	fd = open("screenshot.bmp", O_CREAT | O_RDWR, 0666);
	if (fd < 0)
		exit(0);
	head(fd, all, res, size);
	write(fd, all->list.img.addr, (all->list.width * \
	all->list.height * 4));
	close(fd);
	exit(0);
}

int	main_draw(t_all *all)
{
	all->list.img.img = mlx_new_image(all->list.mlx, \
	all->list.width, all->list.height);
	all->list.img.addr = mlx_get_data_addr(all->list.img.img, \
	&all->list.img.bpp, &all->list.img.line_len, &all->list.img.endian);
	draw_ray_lodev(&all->list);
	draw_sprites(all);
	draw_map(all);
	if (all->save == 1)
	{
		screenshot(all);
		exit(0);
	}
	mlx_put_image_to_window(all->list.mlx, all->list.win, \
	all->list.img.img, 0, 0);
	return (0);
}
