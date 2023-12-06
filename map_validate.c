#include "./so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	terminate_error(char *msg)
{
	ft_putstr_fd(msg, -1);
	exit(EXIT_FAILURE);
}

void	map_texture_validate(char *map)
{
	int	pfg;
	int	efg;

	pfg = 0;
	efg = 0;
	while (*map)
	{
		if (!(*map == '1' || *map == '0' || *map == 'E' || *map == 'C'
				|| *map == 'P' || *map == '\n'))
			terminate_error("Invalid map\n");
		if (*map == 'P')
			pfg++;
		if (*map == 'E')
			efg++;
		map++;
	}
	if (pfg != 1 || efg != 1)
		terminate_error("Invalid map\n");
}

void	map_shape_validate(char *map)
{
	int	width;
	int	tmp;
	int	height;

	width = 0;
	height = 0;
	tmp = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			if (tmp == 0)
				tmp = width;
			if (tmp != width)
				terminate_error("Invalid map\n");
			width = 0;
			map++;
			height++;
			continue ;
		}
		map++;
		width++;
	}
	if (tmp != width)
		terminate_error("Invalid map\n");
}

void	correct_wall_validate(t_map_info map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_info.height)
	{
		while (j < map_info.width)
		{
			if (i == 0 || i == map_info.height - 1 || j == 0
				|| j == map_info.width - 1)
			{
				if (map_info.map[i][j].texture != '1')
					terminate_error("Invalid map\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	map_playable_validate(char *map, t_map_info map_info)
{
	if (map_info.width <= 2 || map_info.height <= 2 || map_info.collectible < 1)
		terminate_error("Invalid map\n");
	map_texture_validate(map);
	correct_wall_validate(map_info);
}

void	map_validate(char *map)
{
	map_shape_validate(map);
}
