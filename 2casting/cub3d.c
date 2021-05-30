#include "../cub3d.h"

int	check_argc(int	argc, char **argv, t_all *all)
{
	all->save = 0;
	if (argc == 2)
		return (1);
	else if (argc == 3)
	{
		if (!ft_strcmp("--save", argv[2]))
			all->save = 1;
		else
		{
			printf("\nWRONG FLAG\n");
			exit(0);
		}
	}
	return (0);
}

int	map_check_symb_2(char *str, int	c, int	b)
{
	int	i;
	int	checkone;

	i = -1;
	checkone = 0;
	if (!str)
		return (1);
	while (str[++i])
	{
		if (str[i] == '1')
			checkone = 1;
		if (str[i] != c && str[i] != b)
			return (1);
	}
	if (checkone == 1)
		return (0);
	return (1);
}

void	exit_cub(char s)
{
	if (s == 'p')
		printf("\nERROR--ERROR--ERROR in the params\n");
	else if (s == 'm')
		printf("\nERROR--ERROR--ERROR in the map\n");
	exit(0);
}

char	**parse_gnl(int fd, t_all *all, char *line)
{
	static t_list	*head;

	head = NULL;
	while (get_next_line(fd, &line))
	{
		check_params_fill(&all->list);
		if (check_params(line, &all->list) == 0)
			exit_cub('p');
		else if (check_params(line, &all->list) == 1 && all->list.check != 1)
		{
			if (all->list.params_fillment == 1 \
			&& !map_check_symb_2(line, ' ', '1'))
				all->list.check = 1;
		}
		if (all->list.check == 1 || all->list.check == 2)
			ft_lstadd_back(&head, ft_lstnew(line));
		else
			free(line);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	if (all->list.params_fillment != 1)
		exit_cub('p');
	return (make_map(&head, ft_lstsize(head)));
}

int	main(int	argc, char **argv)
{
	int		fd;
	char	*line;
	t_all	all;
	char	**map;

	line = NULL;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (argc == 0 || argc > 3 || !argv)
		return (0);
	check_argc(argc, argv, &all);
	init_struct(&all.list);
	map = parse_gnl(fd, &all, line);
	make_square_map(map, &all);
	if (map_checker(map, &all.list, &all) == 0)
		exit_cub('m');
	all.list.map = map;
	fill_dir(&all);
	init_mlx_main(&all);
	return (0);
}
