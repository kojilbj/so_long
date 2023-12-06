#include "./so_long.h"

void	get_map_info(t_map_info *map_info, char *map)
{
	int	width;
	int	height;
	int	collectible;

	width = 0;
	height = 0;
	collectible = 0;
	while(*map)
	{
		if(*map == 'C')
			collectible++;
		if(*map == '\n')
		{
			height++;
			width = 0;
		}
		else
			width++;
		map++;
	}
	map_info->width = width;
	map_info->height = height + 1;
	map_info->collectible = collectible;
}

char	*get_map_as_line(char	*file_path)
{
	int	fd;
	int	i;
	char	*map_line;
	char	buff[10];

	map_line = NULL;
	fd = open(file_path, O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}
	while(1)
	{
		i = read(fd, buff, 9);
		if(i == 0)
			break ;
		buff[i] = 0;
		map_line = ft_strjoin(map_line, buff);
	}
	return (map_line);
}

t_image_info	**get_z_dimention_map(t_map_info *map_info, char *map)
{
	t_image_info	**z_dimention_map;
	int	i;
	int	j;

	z_dimention_map = (t_image_info **)malloc(sizeof(t_image_info *) * (map_info->height + 1));
	i= 0;
	j = 0;
	while(i < map_info->height)
	{
		z_dimention_map[i] = malloc(sizeof(t_image_info) * (map_info->width + 1));
		while(j < map_info->width)
		{
			// ft_printf("%d\n", j);
			z_dimention_map[i][j].texture = *map;
			// ft_printf("%c\n", z_dimention_map[i][j].texture);
			j++;
			map++;
		}
		z_dimention_map[i][j].texture= 'Z';
		j = 0;
		map++;
		i++;
	}
	z_dimention_map[i] = NULL;
	return z_dimention_map;
}
