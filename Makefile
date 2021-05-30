NAME = cub3D

SRC = 	./1parsing/check_tex.c \
		./1parsing/make_map.c \
		./1parsing/map_check.c \
		./1parsing/parse_floor_celling.c \
		./1parsing/parser_utils.c \
		./1parsing/parsing.c \
		./2casting/cub3d.c \
		./2casting/main_draw.c \
		./2casting/mlx_main.c \
		./2casting/draw_map2d.c \
		./2casting/cast_sprite.c \
		./2casting/cast_walls_1.c \
		./2casting/cast_walls_2.c \
		./2casting/load_tex_imgs.c \
		./2casting/cub_utils.c \
		get_next_line1.c \
		get_next_line_utils1.c \

		 
OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework Appkit

%.o: %.c
	$(CC) $(CFLAGS) -c -I./libft1/ -I./mlx/ $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@make -C libft1
	@make -C mlx
	@mv mlx/libmlx.dylib ./
	@$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS) -L. -lmlx  -I./mlx/ ./libft1/libft.a

clean :
	@$(RM) $(OBJ) 
	@make clean -C libft1
	@make clean -C mlx
	
fclean : clean
	@$(RM) $(NAME) screenshot.bmp libmlx.dylib ./libft1/libft.a

re:	fclean all

.PHONY: all clean fclean re