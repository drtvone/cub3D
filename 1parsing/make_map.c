#include "../cub3d.h"

char	**make_map(t_list **head, int	size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	map = ft_calloc(size + 1, sizeof(char *));
	while (tmp)
	{
		map[i++] = tmp->cont;
		tmp = tmp->next;
	}
	return (map);
}

void	make_spaces(char **map, int	lenmax)
{
	int		i;
	int		j;
	char	*temp;
	int		len;

	j = 0;
	i = -1;
	temp = NULL;
	len = 0;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len < lenmax)
		{
			temp = ft_calloc(lenmax + 1, sizeof(char *));
			j = -1;
			while (map[i][++j])
				temp[j] = map[i][j];
			while (j < lenmax)
				temp[j++] = ' ';
			map[i] = temp;
		}
	}
}

int	make_square_map(char **map, t_all *all)
{
	int	i;
	int	len;
	int	j;
	int	lenmax;

	len = 0;
	i = -1;
	lenmax = 0;
	all->spritenumb = 0;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len > lenmax)
			lenmax = len;
	}
	make_spaces(map, lenmax);
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == '2')
				all->spritenumb++;
	}
	return (lenmax);
}
