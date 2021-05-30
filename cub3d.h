#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line1.h"
# include "./mlx/mlx.h"
# include <math.h>
# include "./libft1/libft.h"
# include <fcntl.h>

typedef struct s_data{
	void		*win;
	void		*mlx;
}				t_data;

# define SCALE_SIZE 64
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MVSPEED 0.4763
# define MVROTATE 0.15
# define W 13
# define S 1
# define D 2
# define A 0
# define RIGHT 124
# define LEFT 123
# define ESC 53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		line_len;
	int		bpp;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_point
{
	int		x;
	int		y;
	char	vector;
}				t_point;

typedef struct s_rays
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	int		**buf;
	double	moveSpeed;
	double	rotSpeed;
	double	*zBuffer;
}				t_rays;

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
	float	start;
	float	end;
}				t_player;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	dist;
	int		number;
}				t_sprite;

typedef struct s_rcst
{
	int		mapx;
	int		mapy;
	double	raydirx;
	double	raydiry;
	double	deltadstx;
	double	deltadsty;
	double	sidedstx;
	double	sidedsty;
	int		side;
	int		stepx;
	int		stepy;
	int		drawstart;
	int		drawend;
	int		lineheight;
	double	wallx;
	int		texx;
}				t_rcst;

typedef struct s_scst
{
	int		*spriteorder;
	double	*spritedist;
	double	spritex;
	double	spritey;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
	int		spritewidth;
}				t_scst;

typedef struct s_params
{
	int				check;
	int				width;
	int				height;
	char			*so_path;
	char			*no_path;
	char			*we_path;
	char			*ea_path;
	char			*s_path;
	char			*floor_path;
	char			*celing_path;
	unsigned long	floorclr;
	unsigned long	celingclr;
	int				params_fillment;
	int				player;
	double			x;
	double			y;
	void			*mlx;
	void			*win;
	char			**map;
	t_img			img;
	t_img			west;
	t_img			east;
	t_img			north;
	t_img			south;
	t_img			buf;
	t_rays			rays;
	t_rcst			rcst;
}					t_params;

typedef struct s_all
{
	t_params	list;
	t_point		point;
	t_data		data;
	t_sprite	*sprite;
	t_img		sprtimg;
	t_scst		scst;
	int			save;
	int			spritenumb;
}				t_all;

int				get_next_line(int fd, char **line);
int				check_params_fill(t_params *list);
int				check_params(char *line, t_params *list);
char			**make_map(t_list **head, int size);
int				map_checker(char **map, t_params *list, t_all *all);
int				make_square_map(char **map, t_all *all);
int				map_check_symb(char *str, int c);
unsigned long	createRGB(int	r, int	g, int	b);
int				check_so_path(char *line, t_params *list);
int				check_no_path(char *line, t_params *list);
int				check_we_path(char *line, t_params *list);
int				check_ea_path(char *line, t_params *list);
int				check_s_path(char *line, t_params *list);
int				check_celing_path(char *line, t_params *list);
int				check_floor_path(char *line, t_params *list);
void			screenshot(t_all *all);
void			init_mlx_main(t_all *all);
void			put_sprite_draw(t_all *all, int texx, int texy, int	stripe);
void			calc_start_end_sprite(t_all *all);
void			calc_sprite_xy(t_all *all, int	i);
void			calc_sprite_order(t_all *all);
void			sort_sprites(t_all *all, int	*spriteOrder, \
double *spriteDistance);
void			draw_ray_lodev(t_params *list);
int				draw_map(t_all *all);
void			load_image(t_params *list);
void			load_image_2(t_params *list);
void			load_image_3(t_params *list);
void			load_image_4(t_params *list);
void			load_image_5(t_all *all);
int				main_draw(t_all *all);
void			my_mlx_pixel_put(t_params *list, int	x, int	y, int	color);
void			calc_step(t_params *list);
void			calc_rays(t_params *list, int	x);
void			select_texture(t_params *list, int	side, int	\
stepX, int	stepY);
void			init_struct(t_params *list);
void			fill_dir(t_all *all);
int				key_exit(t_all *all);

#endif