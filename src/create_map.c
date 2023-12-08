#include "../so_long.h"

void	create_window(t_vars *vars, t_map_info map_info)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, map_info.width * PANEL_SIZE, map_info.height * PANEL_SIZE, "so_long");
}

void	mapping_background(t_vars vars, t_map_info map_info)
{
	int	i;
	int	j;
	void	*img;

	img = mlx_xpm_file_to_image(vars.mlx, "./map/background.xpm", &i, &j);
	i = 0;
	j = 0;
	while(i < map_info.height)
	{
		j = 0;
		while(j < map_info.width)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img, j * PANEL_SIZE, i * PANEL_SIZE);
			j++;
		}
		i++;
	}
}

void	image_into_map(t_vars vars, t_map_info *map_info)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	while(i < map_info->height)
	{
		j = 0;
		while(j < map_info->width)
		{
			if(map_info->map[i][j].texture == '1')
				map_info->map[i][j].img = mlx_xpm_file_to_image(vars.mlx, "./map/wall.xpm", &width, &height);
			if(map_info->map[i][j].texture == 'C')
				map_info->map[i][j].img = mlx_xpm_file_to_image(vars.mlx, "./map/collectible.xpm", &width, &height);
			if(map_info->map[i][j].texture == 'P')
				map_info->map[i][j].img = mlx_xpm_file_to_image(vars.mlx, "./map/player.xpm", &width, &height);
			if(map_info->map[i][j].texture == 'E')
				map_info->map[i][j].img = mlx_xpm_file_to_image(vars.mlx, "./map/exit.xpm", &width, &height);
			j++;
		}
		i++;
	}
}

void	put_map_to_window(t_vars vars, t_map_info map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < map_info.height)
	{
		j = 0;
		while(j < map_info.width)
		{
			if(map_info.map[i][j].texture != '0')
				mlx_put_image_to_window(vars.mlx, vars.win, map_info.map[i][j].img, j * PANEL_SIZE, i * PANEL_SIZE);
			j++;
		}
		i++;
	}
}
