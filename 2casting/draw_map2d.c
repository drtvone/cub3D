#include "../cub3d.h"

void	my_mlx_pixel_put(t_params *list, int	x, int	y, int	color)
{
	char	*dst;

	dst = list->img.addr + (y * list->img.line_len + x * (list->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	window_scale(t_params *list, t_point	point, int	color)
{
	t_point	end;

	end.x = (point.x + 1) * 8;
	end.y = (point.y + 1) * 8;
	point.x *= 8;
	point.y *= 8;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			my_mlx_pixel_put(list, point.x++, point.y, color);
		point.x -= 8;
		point.y++;
	}
}

int	draw_map(t_all *all)
{
	int		i;
	int		j;
	t_point	point;
	char	**map;

	i = -1;
	map = all->list.map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
			{
				point.x = j;
				point.y = i;
				window_scale(&all->list, point, 0x0000FF);
			}
		}
	}
	point.x = (int)all->list.x;
	point.y = (int)all->list.y;
	window_scale(&all->list, point, 0xFF2400);
	return (0);
}
