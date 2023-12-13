/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:47 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/13 14:53:08 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_free(char **z_dimention_map)
{
	int	i;

	i = 0;
	while (z_dimention_map[i])
	{
		free(z_dimention_map[i]);
		i++;
	}
}

int	terminate_program(t_vars *vars)
{
	map_free(vars->map_info.map);
	mlx_destroy_image(vars->mlx, vars->map_imgs.background);
	mlx_destroy_image(vars->mlx, vars->map_imgs.collectible);
	mlx_destroy_image(vars->mlx, vars->map_imgs.exit);
	mlx_destroy_image(vars->mlx, vars->map_imgs.player);
	mlx_destroy_image(vars->mlx, vars->map_imgs.wall);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

int	exit_check(t_vars vars)
{
	int				x;
	int				y;
	char	**map;

	x = vars.player_info.curr_x;
	y = vars.player_info.curr_y;
	map = vars.map_info.map;
	if (map[y][x] == 'E'
		&& vars.player_info.collect_count == vars.map_info.collectible_count)
		return (1);
	if (map[y][x] != 'E')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.exit,
			vars.map_info.exit_x * PANEL_SIZE, vars.map_info.exit_y
			* PANEL_SIZE);
	return (0);
}
