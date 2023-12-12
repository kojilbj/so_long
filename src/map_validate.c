#include "../so_long.h"

void	terminate_perror(char *msg, int errnum)
{
	if(errnum != 0)
		errno = errnum;
	perror(msg);
	exit(EXIT_FAILURE);
}

void	file_name_validate(char *arg)
{
	char	*ptr;

	ptr = ft_strrchr(arg, '.');
	if(ft_strncmp(ptr, ".ber\0", 5))
		terminate_perror("Error\nFile name is invalid, *.ber is expected", 22);
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
			terminate_perror("Error\nMap contains invalid charecter", 22);
		if (*map == 'P')
			pfg++;
		if (*map == 'E')
			efg++;
		map++;
	}
	if (pfg != 1 || efg != 1)
		terminate_perror("Error\nMap must has only one P and E", 22);
}

void	map_shape_validate(char *map)
{
	int	width;
	int	tmp;

	width = 0;
	tmp = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			if (tmp == 0)
				tmp = width;
			if (tmp != width)
				terminate_perror("Error\nMap must be rectangle", 22);
			width = 0;
		}
		else
			width++;
		map++;
	}
	if (tmp != width)
		terminate_perror("Error\nMap must be rectangle", 22);
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
					terminate_perror("Error\nMap must surrounded by '1'", 22);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	map_playable_validate(char *map, t_map_info map_info)
{
	if (map_info.width <= 2 || map_info.height <= 2)
		terminate_perror("Error\nMap is too narrow", 22);
	if (map_info.collectible_count < 1)
		terminate_perror("Error\nMap must has at least one 'C'", 22);
	map_texture_validate(map);
	correct_wall_validate(map_info);
}

void	map_validate(char *map)
{
	map_shape_validate(map);
}
