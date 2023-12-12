#include "../so_long.h"

void	create_window(t_vars *vars, t_map_info map_info)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, map_info.width * PANEL_SIZE, map_info.height * PANEL_SIZE, "so_long");
}

void	mapping_background(t_vars vars, t_map_info *map_info)
{
	int	i;
	int	j;
	void	*img;

	img = vars.map_imgs.background;
	i = 0;
	j = 0;
	while(i < map_info->height)
	{
		j = 0;
		while(j < map_info->width)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img, j * PANEL_SIZE, i * PANEL_SIZE);
			j++;
		}
		i++;
	}
}

void	image_into_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < vars->map_info.height)
	{
		j = 0;
		while(j < vars->map_info.width)
		{
			if(vars->map_info.map[i][j].texture == '1')
				vars->map_info.map[i][j].img = vars->map_imgs.wall;
			if(vars->map_info.map[i][j].texture == 'C')
				vars->map_info.map[i][j].img = vars->map_imgs.collectible;
			if(vars->map_info.map[i][j].texture == 'P')
				vars->map_info.map[i][j].img = vars->map_imgs.player;
			if(vars->map_info.map[i][j].texture == 'E')
				vars->map_info.map[i][j].img = vars->map_imgs.exit;
			j++;
		}
		i++;
	}
}

void	put_map_to_window(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < vars.map_info.height)
	{
		j = 0;
		while(j < vars.map_info.width)
		{
			if(vars.map_info.map[i][j].texture != '0')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.map_info.map[i][j].img, j * PANEL_SIZE, i * PANEL_SIZE);
			j++;
		}
		i++;
	}
}
