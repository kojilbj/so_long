/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:17 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 10:52:59 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_window(t_vars *vars)
{
	int	width;
	int	height;

	width = vars->map_info.width * PANEL_SIZE;
	height = vars->map_info.height * PANEL_SIZE;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		terminate_program(*vars, "Error\nmlx_initilize", 0);
	vars->win = mlx_new_window(vars->mlx, width, height, "so_long");
	if (vars->win == NULL)
		terminate_program(*vars, "Error\nmlx_new_window", 0);
}

void	mapping_background(t_vars vars)
{
	int			x;
	int			y;
	void		*img;
	t_map_info	map_info;

	x = 0;
	y = 0;
	map_info = vars.map_info;
	img = vars.map_imgs.background;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img, x * PANEL_SIZE, y
				* PANEL_SIZE);
			x++;
		}
		y++;
	}
}

static void	put_map_to_window_util(t_vars vars, int x, int y)
{
	char		**map;
	t_map_imgs	imgs;

	map = vars.map_info.map;
	imgs = vars.map_imgs;
	if (map[y][x] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs.wall, x * PANEL_SIZE, y
			* PANEL_SIZE);
	if (map[y][x] == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs.collectible, x
			* PANEL_SIZE, y * PANEL_SIZE);
	if (map[y][x] == 'P')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs.player, x * PANEL_SIZE,
			y * PANEL_SIZE);
	if (map[y][x] == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs.exit, x * PANEL_SIZE, y
			* PANEL_SIZE);
}

void	put_map_to_window(t_vars vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars.map_info.height)
	{
		x = 0;
		while (x < vars.map_info.width)
		{
			if (vars.map_info.map[y][x] != '0')
				put_map_to_window_util(vars, x, y);
			x++;
		}
		y++;
	}
}
