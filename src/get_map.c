#include "../so_long.h"

void	get_map_info(t_vars *vars, char *map)
{
	vars->map_info.width = 0;
	vars->map_info.height = 0;
	vars->map_info.collectible_count = 0;
	while(*map)
	{
		if(*map == 'C')
			vars->map_info.collectible_count++;
		if(*map == 'E')
		{
			vars->map_info.exit_x = vars->map_info.width;
			vars->map_info.exit_y = vars->map_info.height;
		}
		if(*map == '\n')
		{
			vars->map_info.height++;
			vars->map_info.width = 0;
		}
		else
			vars->map_info.width++;
		map++;
	}
	vars->map_info.height++;
}

void	set_map_imgs(t_vars *vars)
{
	void	*mlx;
	t_map_imgs	*map_imgs;
	int	width;
	int	height;

	mlx = vars->mlx;
	map_imgs = &vars->map_imgs;
	map_imgs->player = mlx_xpm_file_to_image(mlx, "map/player.xpm", &width, &height);
	map_imgs->exit = mlx_xpm_file_to_image(mlx, "map/exit.xpm", &width, &height);
	map_imgs->collectible = mlx_xpm_file_to_image(mlx, "map/collectible.xpm", &width, &height);
	map_imgs->background = mlx_xpm_file_to_image(mlx, "map/background.xpm", &width, &height);
	map_imgs->wall = mlx_xpm_file_to_image(mlx, "map/wall.xpm", &width, &height);
}

char	*get_map_as_line(char *file_path)
{
	int	fd;
	int	i;
	char	*map_line;
	char	*tmp;
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
		buff[i] = '\0';
		tmp = map_line;
		map_line = ft_strjoin(map_line, buff);
		free(tmp);
	}
	close(fd);
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
			z_dimention_map[i][j].texture = *map;
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
