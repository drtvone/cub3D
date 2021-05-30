#include "../cub3d.h"

void	load_image(t_params *list)
{
	list->west.img = mlx_xpm_file_to_image(list->mlx, list->we_path, \
	&list->west.width, &list->west.height);
	if (list->west.img == NULL)
	{
		printf("\nERROR in 'WE' texture\n");
		exit (0);
	}
	list->west.addr = mlx_get_data_addr(list->west.img, &list->west.bpp, \
	&list->west.line_len, &list->west.endian);
}

void	load_image_2(t_params *list)
{
	list->east.img = mlx_xpm_file_to_image(list->mlx, list->ea_path, \
	&list->east.width, &list->east.height);
	if (list->east.img == NULL)
	{
		printf("\nERROR in 'EA' texture\n");
		exit (0);
	}
	list->east.addr = mlx_get_data_addr(list->east.img, &list->east.bpp, \
	&list->east.line_len, &list->east.endian);
}

void	load_image_3(t_params *list)
{
	list->north.img = mlx_xpm_file_to_image(list->mlx, list->no_path, \
	&list->north.width, &list->north.height);
	if (list->north.img == NULL)
	{
		printf("\nERROR in 'NO' texture\n");
		exit (0);
	}
	list->north.addr = mlx_get_data_addr(list->north.img, &list->north.bpp, \
	&list->north.line_len, &list->north.endian);
}

void	load_image_4(t_params *list)
{
	list->south.img = mlx_xpm_file_to_image(list->mlx, list->so_path, \
	&list->south.width, &list->south.height);
	if (list->south.img == NULL)
	{
		printf("\nERROR in 'SO' texture\n");
		exit (0);
	}
	list->south.addr = mlx_get_data_addr(list->south.img, &list->south.bpp, \
	&list->south.line_len, &list->south.endian);
}

void	load_image_5(t_all *all)
{
	all->sprtimg.img = mlx_xpm_file_to_image(all->list.mlx, all->list.s_path, \
	&all->sprtimg.width, &all->sprtimg.height);
	if (all->sprtimg.img == NULL)
	{
		printf("\nERROR in 'S' texture\n");
		exit (0);
	}
	all->sprtimg.addr = mlx_get_data_addr(all->sprtimg.img, &all->sprtimg.bpp, \
	&all->sprtimg.line_len, &all->sprtimg.endian);
}
