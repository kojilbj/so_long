/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:47 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/12 16:57:45 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	terminate_program(t_vars *vars)
{
	all_free(vars->map_info.map);
	mlx_destroy_image(vars->mlx, vars->map_imgs.background);
	mlx_destroy_image(vars->mlx, vars->map_imgs.collectible);
	mlx_destroy_image(vars->mlx, vars->map_imgs.exit);
	mlx_destroy_image(vars->mlx, vars->map_imgs.player);
	mlx_destroy_image(vars->mlx, vars->map_imgs.wall);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

int	exit_check(t_vars vars)
{
	t_image_info	**map;
	int				curr_x;
	int				curr_y;

	map = vars.map_info.map;
	curr_x = vars.player_info.curr_x;
	curr_y = vars.player_info.curr_y;
	if (map[curr_y][curr_x].texture == 'E'
		&& vars.player_info.collect_count == vars.map_info.collectible_count)
		return (1);
	if (map[curr_y][curr_x].texture != 'E')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.exit,
			vars.map_info.exit_x * PANEL_SIZE, vars.map_info.exit_y
			* PANEL_SIZE);
	return (0);
}
